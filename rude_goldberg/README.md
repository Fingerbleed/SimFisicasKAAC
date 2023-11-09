### Proyecto Parcial 2 - Hola Goldberg

"Diseñar una maquina de Rube Goldberg utilizando Box2D y SFML para su interfaz gráfica. Con un minimo de 10 cuerpos, presetnar joints de distancia, engrane, revolucion,prismatica y polea. y entregarlo a manera de proyecto de CLion con un README y su código fuente"

Para este proyecto debemos hacer una maquina de Goldberg, por lo que vamos a requerir de muchos cuerpos, por lo que decidi crear 2 clases para generarlos rapidamente:
- Body (Clase padre)
Esta clase sirve principalmente para actualizar los cuerpos con SFML durante el game cycle, teniendo definiciones funciones y 1 variable para modificar.
- Circle - Generar circulos
Esta clase genera cuerpos dinamicos con forma de circulos y permite asignarles ubicacion, tamaño y densidad, cuenta con funciones para actualizar el cuerpo con SFML durante el game cycle.
- Box - Generar cajas
Esta clase genera cuerpos con forma de rectangulo y permite asignarles ubicacion, tamaño, angulo, tipo (estatico, dinamico, kinematico) y densidad, cuenta con funciones para actualizar el cuerpo con SFML durante el game cycle.

Para el proyecto, tambien vamos  requerir de distintos joints, por lo que me decidi por generar clases para ellos que tengan distintas funciones para alterar sus atributos facilmente y ahorrar espacio:
- Distance - Genera un joint de distancia entre 2 cuerpos
Cuenta con una funcion para asignarle tamaño y otra para asignarle stiffness y damping.
- Revolute - Genera un joint de revolucion entre 2 cuerpos
Cuenta con una funcion para asignar limites y otra para asignar motor
- Prismatic - Genera un joint de prismatica entre 2 cuerpos
Cuenta con una funcion para asignar limites y otra para asignar motor

Estos y el joint de engranaje son todos los que se utilizan en el proyecto, pero el de engranaje no cuenta con clase debido a algunas complicaciones, por lo que generarlo manualmente resulta mas sencillo.

Al tener estas 2 herramientas, podemos crear la ventana de SFML, el mundo y empezar a inicializar los objetos y joints, aqui esta la lista con descripciones generales en los cuerpos dinamicos y joints de su uso dentro de la simulacion:
```cpp
// 2 cuerpos dinamicos y joint de distancia, empuja a ball hacia revBody  
Circle* distBody1 = new Circle(world, 25, 25, 5);  
Circle* distBody2 = new Circle(world, 25, 55, 5);  
Distance distanceJoint(world, distBody1->getBody(), distBody2->getBody());  

// Cuerpo dinamico que distBody1 empuja hacia revBody y revBody empuja hacia prismBody  
Circle* ball = new Circle(world, 85, 210, 10);  

// 1 cuerpo dinamico y 1 cuerpo estatico que forman un joint de revolucion giratorio, empuja a ball hacia prismBody  
Box* revBody = new Box(world, 5, 240, 10, 35, 0, 1);  
Box* revAnchor = new Box(world, 5, 215, 1, 1, 0);  
Revolute revoluteJoint(world, revAnchor->getBody(), revBody->getBody());  
revoluteJoint.setMotor(true, 20.f, 50.f);  

//1 cuerpo dinamico con movimiento horizontal por un joint prismatico, se ve empujado por ball  
Box* prismBody = new Box(world, 240, 210, 90, 10, 0, 1, 0.5);  
Box* prismAnchor = new Box(world, 800, 210, 10, 10, 0);  
Prismatic prismaticJoint(world, prismAnchor->getBody(), prismBody->getBody(), b2Vec2(1.0f, 0.0f));  
prismaticJoint.setLimit(true, 0.0f, 10.0f);  

//1 cuerpo dinamico con movimiento horizontal por un joint prismatico, se ve manipulado por un joint de engranaje y sirve como plataforma para ball  
Box* prismBody2 = new Box(world, 250, 350, 100, 10, 0, 1, 3.1);  
Prismatic prismaticJoint2(world, prismAnchor->getBody(), prismBody2->getBody(), b2Vec2(1.0f, 0.0f));  
prismaticJoint2.setLimit(true, -20.0f, 0.0f);  

//Gear entre los 2 joints prismaticos, joint B se mueve en direccion contraria que joint A  
b2GearJointDef jointDef;  
jointDef.bodyA = prismBody->getBody();  
jointDef.bodyB = prismBody2->getBody();  
jointDef.joint1 = prismaticJoint.getJoint();  
jointDef.joint2 = prismaticJoint2.getJoint();  
b2GearJoint* joint = (b2GearJoint*)world.CreateJoint(&jointDef);  

//1 cuerpo dinamico con movimiento vertical, se ve empujado hacia abajo por box  
Box* prismBody3 = new Box(world, 250, 265, 60, 10, 0, 1);  
Prismatic prismaticJoint3(world, prismAnchor->getBody(), prismBody3->getBody(), b2Vec2(0.0f, 1.0f));  
prismaticJoint3.setLimit(true, -15.0f, 15.0f);  

//1 cuerpo dinamico con movimiento vertical, se ve manipulado por un joint de engranaje, mueve a distBody3  
Box* prismBody4 = new Box(world, 450, 190, 25, 10, 0, 1, 3.0f);  
Prismatic prismaticJoint4(world, prismAnchor->getBody(), prismBody4->getBody(), b2Vec2(0.0f, 1.0f));  
prismaticJoint4.setLimit(true, -15.0f, 15.0f);  

//Gear entre 2 joints prismaticos joint B se mueve en direccion contraria que joint A  
b2GearJointDef jointDef2;  
jointDef2.bodyA = prismBody3->getBody();  
jointDef2.bodyB = prismBody4->getBody();  
jointDef2.joint1 = prismaticJoint3.getJoint();  
jointDef2.joint2 = prismaticJoint4.getJoint();  
b2GearJoint* joint2 = (b2GearJoint*)world.CreateJoint(&jointDef2);  

// Caja que se ve afectada cuando los prismaticos del primer joint de engranaje se mueven, empujando prismBody3 para abajo y bloqueando el movimiendo de prismBody2  
Box* box = new Box(world, 250, 190, 35, 35, 0, 1);  

// 2 cuerpos dinamicos y joint de distancia, empuja a ball2 hacia prismBody al moverse  
Circle* distBody3 = new Circle(world, 450, 170, 14, 0.1f);  
Circle* distBody4 = new Circle(world, 410, 170, 15, 0.1f);  
Distance distanceJoint2(world, distBody3->getBody(), distBody4->getBody());  

// cuerpo dinamico que al moverse usa prismBody como plataforma para empujar a ball a la meta  
Circle* ball2 = new Circle(world, 370, 80, 25);
```

Despues de esto, gracias a la clase Body me es posible generar un array que contenga todos los cuerpos, esto para ahorrar aun mas espacio y poder agregar y eliminar cuerpos de la simulacion de forma rapida y sencilla, ya que en el game cycle se utiliza este array en unos ciclos for.

Para finalizar ocurre el game cycle el cual ocurre mientras la ventana este abierta, este permite presionar Z para cerrar la ventana y actualiza la simulacion usando steps y se actualiza la ventana de la siguiente forma:
1. Se actualizan los cuerpos en un ciclo for llamando la funcion update()
2. Se limpia la ventana
3. Se agregan los cuerpos a la ventana con un ciclo for llamando la funcion draw()
4. Se muestran los elementos de la ventana


```cpp
#include <SFML/Graphics.hpp>  
#include <Box2D/Box2D.h>  
  
constexpr float SCALE = 10.0f;  
  
// Clase padre con para actualizar cuerpos  
class Body {  
public:  
    virtual void update() = 0;  
    virtual void draw(sf::RenderWindow &win) const = 0;  
  
    b2Body *getBody() {  
        return body;  
    }  
  
protected:  
    b2Body *body{};  
};  
  
// Clase hija para crear y actualizar circulos dinamicas  
class Circle : public Body {  
public:  
    Circle(b2World &world, float x, float y, float size, float density = 1.0f) {  
        b2BodyDef bodydef;  
        bodydef.position.Set(x / SCALE, y / SCALE);  
        bodydef.type = b2_dynamicBody;  
        body = world.CreateBody(&bodydef);  
  
        b2CircleShape shape;  
        shape.m_radius = size / SCALE;  
  
        b2FixtureDef fixturedef;  
        fixturedef.shape = &shape;  
        fixturedef.density = density;  
        body->CreateFixture(&fixturedef);  
  
        circle.setRadius(size);  
        circle.setFillColor(sf::Color::Red);  
        circle.setOrigin(size, size);  
    }  
  
    void update() override {  
        circle.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);  
        circle.setRotation(body->GetAngle() * 180 / b2_pi);  
    }  
  
    void draw(sf::RenderWindow &win) const override {  
        win.draw(circle);  
    }  
  
private:  
    sf::CircleShape circle;  
};  
  
// Clase para crear y actualizar cajas de distintos tipos  
class Box : public Body {  
public:  
    Box(b2World &world, float x, float y, float size_x, float size_y, float angle, int type = 0, float density = 1.0f) {  
        b2BodyDef bodydef;  
        bodydef.position.Set(x / SCALE, y / SCALE);  
        bodydef.angle = angle * (b2_pi / 180);  
  
        switch(type) {  
            case 0:  
                bodydef.type = b2_staticBody;  
                box.setFillColor(sf::Color::Blue);  
                break;  
            case 1:  
                bodydef.type = b2_dynamicBody;  
                box.setFillColor(sf::Color::Red);  
                break;  
            case 2:  
                bodydef.type = b2_kinematicBody;  
                box.setFillColor(sf::Color::Green);  
                break;  
            default:  
                bodydef.type = b2_staticBody;  
                box.setFillColor(sf::Color::Blue);  
                break;  
        }  
  
        body = world.CreateBody(&bodydef);  
  
        b2PolygonShape shape;  
        shape.SetAsBox((size_x / 2) / SCALE, (size_y / 2) / SCALE);  
  
        b2FixtureDef fixturedef;  
        fixturedef.shape = &shape;  
        fixturedef.density = density;  
        body->CreateFixture(&fixturedef);  
  
        box.setSize(sf::Vector2f(size_x, size_y));  
        box.setOrigin(size_x / 2, size_y / 2);  
    }  
  
    void update() override {  
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);  
        box.setRotation(body->GetAngle() * 180 / b2_pi);  
    }  
  
    void draw(sf::RenderWindow &win) const override {  
        win.draw(box);  
    }  
  
private:  
    sf::RectangleShape box;  
};  
  
// Clase para crear y modificar joints de distancia  
class Distance {  
public:  
    Distance(b2World &world, b2Body *bodyA, b2Body *bodyB) {  
        jointDef.Initialize(bodyA, bodyB, bodyA->GetWorldCenter(), bodyB->GetWorldCenter());  
        joint = (b2DistanceJoint*)world.CreateJoint(&jointDef);  
    }  
  
    b2DistanceJoint *getJoint() {  
        return joint;  
    }  
  
    void setLength(float length, float min_length, float max_length) {  
        joint->SetMinLength(min_length);  
        joint->SetMaxLength(max_length);  
        joint->SetLength(length);  
    }  
  
    void setAttributes(float stiffness, float damping) {  
        joint->SetStiffness(stiffness);  
        joint->SetDamping(damping);  
    }  
  
private:  
    b2DistanceJointDef jointDef;  
    b2DistanceJoint* joint;  
};  
  
// Clase para crear y modificar joints de revolucion  
class Revolute {  
public:  
    Revolute(b2World &world, b2Body *bodyA, b2Body *bodyB) {  
        jointDef.Initialize(bodyA, bodyB, bodyA->GetWorldCenter());  
        joint = (b2RevoluteJoint*)world.CreateJoint(&jointDef);  
    }  
  
    b2RevoluteJoint *getJoint() {  
        return joint;  
    }  
  
    void setLimit(bool isEnabled, float lower = 0, float upper = 0) {  
        joint->EnableLimit(isEnabled);  
        joint->SetLimits(lower, upper);  
    }  
  
    void setMotor(bool isEnabled, float speed = 0, float max_torque = 0) {  
        joint->EnableMotor(isEnabled);  
        joint->SetMotorSpeed(speed);  
        joint->SetMaxMotorTorque(max_torque);  
    }  
  
private:  
    b2RevoluteJointDef jointDef;  
    b2RevoluteJoint* joint;  
};  
  
// Clase para crear y modificar joints de prismatica  
class Prismatic {  
public:  
    Prismatic(b2World &world, b2Body *bodyA, b2Body *bodyB, b2Vec2 axis) {  
        jointDef.Initialize(bodyA, bodyB, bodyA->GetWorldCenter(), axis);  
        joint = (b2PrismaticJoint*)world.CreateJoint(&jointDef);  
    }  
  
    b2PrismaticJoint *getJoint() {  
        return joint;  
    }  
  
    void setLimit(bool isEnabled, float lower = 0, float upper = 0) {  
        joint->EnableLimit(isEnabled);  
        joint->SetLimits(lower, upper);  
    }  
  
    void setMotor(bool isEnabled, float speed = 0, float max_force = 0) {  
        joint->EnableMotor(isEnabled);  
        joint->SetMotorSpeed(speed);  
        joint->SetMaxMotorForce(max_force);  
    }  
  
private:  
    b2PrismaticJointDef jointDef;  
    b2PrismaticJoint* joint;  
};  
  
  
int main() {  
    // Creacion de ventana  
    sf::RenderWindow window(sf::VideoMode(500, 450), "Maquina de Rube Goldberg");  
  
    // Creacion de mundo  
    b2Vec2 gravity(0.0f, 0.1f);  
    b2World world(gravity);  
  
    // Creacion de cuerpos estaticos  
    Box* platform1 = new Box(world, 0, 30, 250, 5, 20);  
    Box* platform2 = new Box(world, 115, 135, 5, 125, 0);  
    Box* platform3 = new Box(world, 0, 140, 250, 5, 25);  
    Box* platform4 = new Box(world, 100, 225, 100, 5, 0);  
    Box* platform5 = new Box(world, 215, 135, 5, 125, 0);  
    Box* platform6 = new Box(world, 215, 280, 5, 125, 0);  
    Box* platform7 = new Box(world, 285, 135, 5, 125, 0);  
    Box* platform8 = new Box(world, 285, 280, 5, 125, 0);  
    Box* platform9 = new Box(world, 450, 200, 35, 10, 0);  
    Box* platform10 = new Box(world, 470, 130, 10, 150, 0);  
    Box* platform11 = new Box(world, 430, 130, 10, 150, 0);  
    Box* platform12 = new Box(world, 450, 60, 35, 10, 0);  
    Box* platform13 = new Box(world, 370, 130, 25, 5, 0);  
    Box* platform14 = new Box(world, 300, 185, 25, 5, 45);  
    Box* platform15 = new Box(world, 95, 350, 5, 50, 0);  
    Box* platform16 = new Box(world, 260, 420, 150, 5, -1);  
    Box* platform17 = new Box(world, 410, 305, 25, 5, -45);  
    Box* platform18 = new Box(world, 73, 440, 10, 5, 20);  
    Box* platform19 = new Box(world, 106, 440, 50, 5, -1);  
  
    // Creacion de cuerpos estaticos (Objetivo final)  
    Box* end1 = new Box(world, 36, 450, 60, 5, 0, 2);  
    Box* end2 = new Box(world, 6, 445, 5, 10, 0, 2);  
    Box* end3 = new Box(world, 66, 445, 5, 10, 0, 2);  
  
    // 2 cuerpos dinamicos y joint de distancia, empuja a ball hacia revBody  
    Circle* distBody1 = new Circle(world, 25, 25, 5);  
    Circle* distBody2 = new Circle(world, 25, 55, 5);  
    Distance distanceJoint(world, distBody1->getBody(), distBody2->getBody());  
  
    // Cuerpo dinamico que distBody1 empuja hacia revBody y revBody empuja hacia prismBody  
    Circle* ball = new Circle(world, 85, 210, 10);  
  
    // 1 cuerpo dinamico y 1 cuerpo estatico que forman un joint de revolucion giratorio, empuja a ball hacia prismBody  
    Box* revBody = new Box(world, 5, 240, 10, 35, 0, 1);  
    Box* revAnchor = new Box(world, 5, 215, 1, 1, 0);  
    Revolute revoluteJoint(world, revAnchor->getBody(), revBody->getBody());  
    revoluteJoint.setMotor(true, 20.f, 50.f);  
  
    //1 cuerpo dinamico con movimiento horizontal por un joint prismatico, se ve empujado por ball  
    Box* prismBody = new Box(world, 240, 210, 90, 10, 0, 1, 0.5);  
    Box* prismAnchor = new Box(world, 800, 210, 10, 10, 0);  
    Prismatic prismaticJoint(world, prismAnchor->getBody(), prismBody->getBody(), b2Vec2(1.0f, 0.0f));  
    prismaticJoint.setLimit(true, 0.0f, 10.0f);  
  
    //1 cuerpo dinamico con movimiento horizontal por un joint prismatico, se ve manipulado por un joint de engranaje y sirve como plataforma para ball  
    Box* prismBody2 = new Box(world, 250, 350, 100, 10, 0, 1, 3.1);  
    Prismatic prismaticJoint2(world, prismAnchor->getBody(), prismBody2->getBody(), b2Vec2(1.0f, 0.0f));  
    prismaticJoint2.setLimit(true, -20.0f, 0.0f);  
  
    //Gear entre los 2 joints prismaticos, joint B se mueve en direccion contraria que joint A  
    b2GearJointDef jointDef;  
    jointDef.bodyA = prismBody->getBody();  
    jointDef.bodyB = prismBody2->getBody();  
    jointDef.joint1 = prismaticJoint.getJoint();  
    jointDef.joint2 = prismaticJoint2.getJoint();  
    b2GearJoint* joint = (b2GearJoint*)world.CreateJoint(&jointDef);  
  
    //1 cuerpo dinamico con movimiento vertical, se ve empujado hacia abajo por box  
    Box* prismBody3 = new Box(world, 250, 265, 60, 10, 0, 1);  
    Prismatic prismaticJoint3(world, prismAnchor->getBody(), prismBody3->getBody(), b2Vec2(0.0f, 1.0f));  
    prismaticJoint3.setLimit(true, -15.0f, 15.0f);  
  
    //1 cuerpo dinamico con movimiento vertical, se ve manipulado por un joint de engranaje, mueve a distBody3  
    Box* prismBody4 = new Box(world, 450, 190, 25, 10, 0, 1, 3.0f);  
    Prismatic prismaticJoint4(world, prismAnchor->getBody(), prismBody4->getBody(), b2Vec2(0.0f, 1.0f));  
    prismaticJoint4.setLimit(true, -15.0f, 15.0f);  
  
    //Gear entre 2 joints prismaticos joint B se mueve en direccion contraria que joint A  
    b2GearJointDef jointDef2;  
    jointDef2.bodyA = prismBody3->getBody();  
    jointDef2.bodyB = prismBody4->getBody();  
    jointDef2.joint1 = prismaticJoint3.getJoint();  
    jointDef2.joint2 = prismaticJoint4.getJoint();  
    b2GearJoint* joint2 = (b2GearJoint*)world.CreateJoint(&jointDef2);  
  
    // Caja que se ve afectada cuando los prismaticos del primer joint de engranaje se mueven, empujando prismBody3 para abajo y bloqueando el movimiendo de prismBody2  
    Box* box = new Box(world, 250, 190, 35, 35, 0, 1);  
  
    // 2 cuerpos dinamicos y joint de distancia, empuja a ball2 hacia prismBody al moverse  
    Circle* distBody3 = new Circle(world, 450, 170, 14, 0.1f);  
    Circle* distBody4 = new Circle(world, 410, 170, 15, 0.1f);  
    Distance distanceJoint2(world, distBody3->getBody(), distBody4->getBody());  
  
    // cuerpo dinamico que al moverse usa prismBody como plataforma para empujar a ball a la meta  
    Circle* ball2 = new Circle(world, 370, 80, 25);  
  
    // Array de cuerpos a renderear  
    Body* Bodies[34] = {  
            platform1,  
            platform2,  
            platform3,  
            platform4,  
            platform5,  
            platform6,  
            platform7,  
            platform8,  
            platform9,  
            platform10,  
            platform11,  
            platform12,  
            platform13,  
            platform14,  
            platform15,  
            platform16,  
            platform17,  
            platform18,  
            platform19,  
            end1,  
            end2,  
            end3,  
            distBody1,  
            distBody2,  
            distBody3,  
            distBody4,  
            revBody,  
            prismBody,  
            prismBody2,  
            prismBody3,  
            prismBody4,  
            ball,  
            ball2,  
            box,  
    };  
  
    // Game cycle  
    while (window.isOpen()) {  
        sf::Event event{};  
        // Cerrar ventana  
        while (window.pollEvent(event)) {  
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {  
                window.close();  
                return 0;  
            }  
        }  
  
        // Avanzar la simulacion  
        world.Step(1 / 60.f, 8, 3);  
  
        // Ciclo para actualizar la posicion & angulo de los cuerpos  
        for (auto & Body : Bodies) {  
            Body->update();  
        }  
  
        // Limpiar los objetos de la ventana  
        window.clear();  
  
        // Ciclo para dibujar los cuerpos  
        for (auto & Body : Bodies) {  
            Body->draw(window);  
        }  
  
        // Mostrar los cuerpos en la ventana  
        window.display();  
    }  
    return 0;  
}
```

Este proyecto aunque parecia algo complejo, al empezar a comprender de forma mas profunda los joints se volvio algo mas sencillo y facil de trabajar, siendo de mucha ayuda para finalmente terminar de comprender muchos funcionamientos de box2D y SFML, al ahora poder visualizar todo y manipularlo en su totalidad.