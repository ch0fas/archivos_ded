// Tipos de datos abstractos
// Tipos definidos por el programador formados por un grupo de datos y un conjunto de operaciones
// que se pueden realizar con estos datos
// Como clases y métodos y atributos
// Vamos a usar interfaz (.h) e implementación (.c, todo lo que el usuario no necesita ver)

#include <stdio.h>
#include "shapes/Vec3.h"

int main()
{
    Vec3 v1 = vec3_create(5,1,2);
    vec3_print(v1);
    Vec3 v2 = vec3_create(2, 3, 4);
    vec3_print(v2);
    printf("Memory address: %p\n", v1);
    printf("Valor original de x: %lf\n", vec3_getX(v1));
    vec3_setX(v1, 3);
    printf("Cambiando x: %lf\n", vec3_getX(v1));

    printf("Magnitud de v1: %.2lf\n", vec3_getMagnitude(v1));
    printf("V1 normalizado:\n");
    vec3_print(vec3_normalized(v1));
    printf("Dot Product de v1 y v2: %lf\n", vec3_point_product(v1, v2));
    Vec3 v3 = vec3_clone(v2);
    printf("v1 == v2? %d\n", vec3_equals(v1, v2));
    printf("v3 == v2? %d\n", vec3_equals(v3, v2));

    vec3_destroy(v1);
    vec3_destroy(v2);
    vec3_destroy(v3);
    return 0;
}
