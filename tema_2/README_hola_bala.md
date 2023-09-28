### Tarea 4 - Hola Bala

Esta actividad es algo diferente, ya que en vez de simular un objeto cayendo simulamos la distancia que recorrera una bala al ser disparada, en este caso modificando el codigo visto en clase para que sea una bala de cañon en la luna a 900km/h a 60 grados.

```cpp
#include <Box2D/Box2D.h>  
// Agregamos la libreria cmath para poder realizar calculos mas complejos de forma sencilla
#include <cmath>  
#include <iostream>  

// Definimos PI para poder utilizarla en calculos
#ifndef M_PI  
#define M_PI 3.14159265358979323846  
#endif  
  
int main() {  
    // Asignamos la gravedad de la luna  
    b2Vec2 gravity(0.0f, -1.625f);  
    b2World world(gravity);  
  
    // Definimos la bala  
    b2BodyDef bodyDef;  
    bodyDef.type = b2_dynamicBody;  
    bodyDef.position.Set(0.0f, 0.0f);  
    b2Body* body = world.CreateBody(&bodyDef);  
  
    b2PolygonShape dynamicBox;  
    dynamicBox.SetAsBox(0.2f, 0.05f);  
  
    b2FixtureDef fixtureDef;  
    fixtureDef.shape = &dynamicBox;  
    fixtureDef.density = 0.1f;  
    fixtureDef.friction = 0.3f;  
  
    body->CreateFixture(&fixtureDef);  
  
    // Definimos el angulo y velocidad inicial de la bala en X y Y  
    // Asignamos el nuevo angulo    float angle = 60.0f; // Ángulo en grados  
    // Asignamos la nueva velocidad y la convertimos de km/h a m/s multiplicando por 0.2778    float speed = 900.0f * 0.2778; // Velocidad en m/s  
    float vx = speed * std::cos(angle * M_PI / 180.0f);  
    float vy = speed * std::sin(angle * M_PI / 180.0f);  
  
    // Le asignamos la velocidad a la bala  
    body->SetLinearVelocity(b2Vec2(vx, vy));  
  
    float timeStep = 1.0f / 60.0f;  
    int32 velocityIterations = 6;  
    int32 positionIterations = 2;  
  
    for (int i = 0; i < 60; ++i) {  
        world.Step(timeStep, velocityIterations, positionIterations);  
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;  
    }  

	
    world.DestroyBody(body);  
    return 0;  
}
```

El objeto esta vez no cambia solamente en X la cual disminuia, si no que ahora X aumenta asi como Y tambien debido a que se encuentra en angulo y contiene una velocidad inicial, debido al tiempo de la simulacion no se puede denotar en gran medida el efecto de la gravedad.