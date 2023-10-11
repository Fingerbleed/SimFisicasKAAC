### Tarea 6

*"Utilizando PolygonShape de Box2d Crear las siguientes figuras: Triangulo Rectangulo, Cuadrado, Pentagono, Hexagono y Octagono."*

Gracias a los conocimientos que obtuvimos en la tarea 5, donde investigamos sobre las colisiones en Box2D, aprendimos acerca de los distintos tipos de poligonos y formas que son posibles de crear con las funciones por defecto de la libreria; para practicar estos conocimientos, debemos crear algunas figuras utilizando las funciones de polygon shape.

### Codigo
```cpp
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
```

Como se puede ver, para generar cualquier figura primero se hace un array de vectores que contienen las ubicaciones de los vertices, estos deben de ir en orden contrareloj, ademas se debe de apuntar el numero de vertices, para despues asignar estos 2 valores a un b2PolygonShape.

Debido al gran uso que se le da a los cuadrados, Box2D viene con una funcion que permite generar un cuadrado de forma rapida simplemente colocando el tamaño en X y Y. Se debe tener en cuenta que al generar el cuadrado de esta forma tendra un offset de la mitad del tamaño debido a que se genera de forma centralizada en el el punto inicial.
	Ejemplo: Creamos un cubo de tamaño (1, 1) en las coordenadas (0, 0), por lo que la equina inferior izquierda se encontrara en las coordenadas (-0.5, -0.5), indicando que (0,0) es el centro del cubo.