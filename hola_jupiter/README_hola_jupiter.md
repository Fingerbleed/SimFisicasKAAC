### Tarea 3 - Hola Jupiter

En esta actividad continuamos modificando el codigo de la primera tarea, pero esta vez haciendo una simulacion en Jupiter, ademas de utilizar carburo de tungsteno como el objeto, por lo que se vera afectada la gravedad y la densidad del objeto.

```cpp
#include <iostream>
#include <box2d/box2d.h>

int main()

{
	// Se modifica la gravedad para que represente a Jupiter
    b2Vec2 gravity(0.0f, -24.79f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f,1.0f);

	groundBody ->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    // La altura a la que se encuentra el objeto se disminuye en 5
    bodyDef.position.Set(0.0f, 15.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicbox;
    dynamicbox.SetAsBox(1.0f,1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicbox;
    // La densidad se cambia para representar el carburo de tungsteno
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.9f;

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f;

    int velocityIterations = 6;
    int positionIterations = 2;

    for (int i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);

        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }

    return  0;
}
```

El objeto cae extremadamente rapido en esta simulacion, siendo la mayor velocidad que se ha alcanzado en todas las simulaciones.
