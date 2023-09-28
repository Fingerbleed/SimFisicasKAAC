#include <iostream>
#include <box2d/box2d.h>

int main()

{
    // Se crea el mundo y su gravedad, representando la tierra.
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);

    // Se definen las caracteristicas del piso, asignandole una posicion.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);

    // Se crea el piso
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Se crea la forma del piso
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f,1.0f);

    // Se le asigna densidad al piso
    groundBody ->CreateFixture(&groundBox, 0.0f);

    // Se definen las caracteristicas basicas del objeto, haciendolo dinamico para que se pueda mover y asignandole una posicion.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 20.0f);

    // Se crea el objeto
    b2Body* body = world.CreateBody(&bodyDef);

    // Se crea la forma del objeto
    b2PolygonShape dynamicbox;
    dynamicbox.SetAsBox(1.0f,1.0f);

    // Se definen mas caracteristicas del objeto, como la forma, densidad y friccion
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicbox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    // Se le asignan las caracteristicas al objeto
    body ->CreateFixture(&fixtureDef);

    // Se define la cantidad de verificaciones de la simulacion por segundo (60 verificaciones cada segundo)
    float timeStep = 1.0f/60.0f;

	// Se definen la cantidad de iteraciones a verificar de la velocidad y posicion
    int velocityIterations = 6;
    int positionIterations = 2;

    // Se crea un ciclo para simular 60 verificaciones, osea el paso de 1 segundo
    for (int i = 0; i < 60; ++i)
    {
	//Se le pide al mundo que avance en una verificacion
        world.Step(timeStep, velocityIterations, positionIterations);

	// Se obtienen e imprimen la posicion y angulo del objeto.
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }

    return  0;
}