#include <Box2D/Box2D.h>
#include <iostream>

int main() {
    // Triangulo Rectangulo
    b2Vec2 vertices1[3];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(0.0f, 1.0f);
    int32 count1 = 3;
    b2PolygonShape triangulo_rectangulo;
    triangulo_rectangulo.Set(vertices1, count1);

    // Cuadrado
    b2Vec2 vertices2[4];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(1.0f, 1.0f);
    vertices[3].Set(0.0f, 1.0f);
    int32 count2 = 4;
    b2PolygonShape cuadrado1;
    cuadrado1.Set(vertices2, count2);

    b2PolygonShape cuadrado2;
    cuadrado2.SetAsBox(0.2f, 0.05f);

    //Pentagono
    b2Vec2 vertices3[4];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(1.3f, 0.7f);
    vertices[3].Set(0.5f, 1.0f);
    vertices[4].Set(-0.3f, 0.7f);
    int32 count3 = 5;
    b2PolygonShape pentagono;
    pentagono.Set(vertices3, count3);

    //Hexagono
    b2Vec2 vertices4[5];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(1.2f, 0.5f);
    vertices[3].Set(1.0f, 1.0f);
    vertices[4].Set(0.0f, 1.0f);
    vertices[5].Set(-0.2f, 0.5f);
    int32 count4 = 6;
    b2PolygonShape hexagono;
    hexagono.Set(vertices4, count4);

    //Octagono
    b2Vec2 vertices5[7];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(1.0f, 0.0f);
    vertices[2].Set(2.0f, 1.0f);
    vertices[3].Set(2.0f, 2.0f);
    vertices[4].Set(1.0f, 3.0f);
    vertices[5].Set(0.0f, 3.0f);
    vertices[6].Set(-1.0f, 2.0f);
    vertices[7].Set(-1.0f, 1.0f);
    int32 count5 = 8;
    b2PolygonShape octagono;
    octagono.Set(vertices5, count5);

    return 0;
}