### Tarea 2 - Hola Luna

En esta actividad modificamos el codigo de la tarea anterior para familializarnos de mejor manera, cambiando valores para que el objeto simule caer desde la luna en vez de la tierra, especificamente se modifico la gravedad y friccion.

```cpp
#include <iostream>
#include <box2d/box2d.h>

int main()

{
	// Se modifica la gravedad a un sexto de si misma para representar a la luna
    b2Vec2 gravity(0.0f, -1,62f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f,1.0f);

	groundBody ->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 20.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicbox;
    dynamicbox.SetAsBox(1.0f,1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicbox;
    fixtureDef.density = 1.0f;

	// Se elimina la friccion para representar a la luna
    fixtureDef.friction = 0.0f;

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

Al comparar con la simulacion de la tarea anterior, se puede ver como el objeto cae mucho mas lento debido al cambio de gravedad.
