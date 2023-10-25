#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

constexpr float SCALE = 30.0f;

class Cube {
public:
    Cube(b2World &world, float x, float y) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_dynamicBody;
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((10.f / 2) / SCALE, (10.f / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = 1.0f;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(10.f, 10.f));
        box.setFillColor(sf::Color::Red);
        box.setOrigin(5.f, 5.f);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 450), "JOINTS BIEN INSANOS");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,450.0f / SCALE);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(500.0f,1.0f);
    groundBody ->CreateFixture(&groundBox, 0.0f);

    Cube distance1(world, 50, 150);
    Cube distance2(world, 50, 200);
    b2DistanceJointDef distanceJoint;
    distanceJoint.Initialize(distance1.getBody(), distance2.getBody(), distance1.getBody()->GetWorldCenter(), distance2.getBody()->GetWorldCenter());
    distanceJoint.length = 5.0f;
    world.CreateJoint(&distanceJoint);

    Cube revolute1(world, 100, 150);
    Cube revolute2(world, 105, 155);
    b2RevoluteJointDef revoluteJoint;
    revoluteJoint.Initialize(revolute1.getBody(), revolute2.getBody(), revolute1.getBody()->GetWorldCenter());
    revoluteJoint.lowerAngle = -0.5f * b2_pi; // -90 degrees
    revoluteJoint.upperAngle = 0.25f * b2_pi; // 45 degrees
    revoluteJoint.enableLimit = true;
    revoluteJoint.maxMotorTorque = 10.0f;
    revoluteJoint.motorSpeed = 0.0f;
    revoluteJoint.enableMotor = true;
    revoluteJoint.motorSpeed = 0.0f;
    revoluteJoint.enableMotor = true;
    b2RevoluteJoint* revjoint = (b2RevoluteJoint*)world.CreateJoint(&revoluteJoint);

    Cube prismatic1(world, 150, 150);
    Cube prismatic2(world, 150, 200);
    b2PrismaticJointDef prismaticJoint;
    b2Vec2 worldAxis(1.0f, 0.0f);
    prismaticJoint.Initialize(prismatic1.getBody(), prismatic2.getBody(), prismatic1.getBody()->GetWorldCenter(), worldAxis);
    prismaticJoint.lowerTranslation = -5.0f;
    prismaticJoint.upperTranslation = 2.5f;
    prismaticJoint.enableLimit = true;
    prismaticJoint.maxMotorForce = 1.0f;
    prismaticJoint.motorSpeed = 0.0f;
    prismaticJoint.enableMotor = true;
    b2PrismaticJoint* prismjoint = (b2PrismaticJoint*)world.CreateJoint(&prismaticJoint);

    b2GearJointDef gearJoint;
    gearJoint.bodyA = revolute1.getBody();
    gearJoint.bodyB = prismatic1.getBody();
    gearJoint.joint1 = revjoint;
    gearJoint.joint2 = prismjoint;
    gearJoint.ratio = 2.0f * b2_pi / 50.0f;
    world.CreateJoint(&gearJoint);

    Cube weld1(world, 200, 150);
    Cube weld2(world, 200, 200);
    b2WeldJointDef weldJoint;
    weldJoint.Initialize(weld1.getBody(), weld2.getBody(), weld1.getBody()->GetWorldCenter());
    world.CreateJoint(&weldJoint);

    Cube wheel1(world, 250, 150);
    Cube wheel2(world, 250, 200);
    b2WheelJointDef wheelJoint;
    wheelJoint.Initialize(wheel1.getBody(), wheel2.getBody(), wheel1.getBody()->GetWorldCenter(), worldAxis);
    world.CreateJoint(&wheelJoint);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                distance1.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
                revolute1.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
                prismatic1.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
                weld1.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
                wheel1.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                distance1.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
                revolute1.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
                prismatic1.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
                weld1.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
                wheel1.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                distance1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
                revolute1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
                prismatic1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
                weld1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
                wheel1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                distance1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
                revolute1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
                prismatic1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
                weld1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
                wheel1.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                distance1.stop();
                revolute1.stop();
                prismatic1.stop();
                weld1.stop();
                wheel1.stop();
            }
            // The Z key event to close the window
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
                return 0; // return from the main function, effectively ending the program
            }
        }

        world.Step(1 / 60.f, 8, 3);

        distance1.update();
        distance2.update();
        revolute1.update();
        revolute2.update();
        prismatic1.update();
        prismatic2.update();
        weld1.update();
        weld2.update();
        wheel1.update();
        wheel2.update();

        window.clear();

        distance1.draw(window);
        distance2.draw(window);
        revolute1.draw(window);
        revolute2.draw(window);
        prismatic1.draw(window);
        prismatic2.draw(window);
        weld1.draw(window);
        weld2.draw(window);
        wheel1.draw(window);
        wheel2.draw(window);

        window.display();
    }
    return 0;
}