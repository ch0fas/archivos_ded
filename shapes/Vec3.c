// Implementación (privado)
// La struct no se puede llamar Vec3, le ponemos str(struct)Vec3

#include "Vec3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct strVec3
{
    double x, y, z;
};

Vec3 vec3_create(double x, double y, double z)
{
    Vec3 v = (Vec3) malloc(sizeof(struct strVec3));
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void vec3_destroy(Vec3 v)
{
    free(v);
    printf("Vector eliminado\n");
}

double vec3_getX(Vec3 v)
{
    return v->x;
}

void vec3_setX(Vec3 v, double x)
{
    // Aquí pondríamos cualquier verificador de validez de datos, por ahora no tho
    v->x = x;
}

double vec3_getY(Vec3 v)
{
    return v->y;
}

void vec3_setY(Vec3 v, double y)
{
    // Aquí pondríamos cualquier verificador de validez de datos, por ahora no tho
    v->y = y;
}

double vec3_getZ(Vec3 v)
{
    return v->z;
}

void vec3_setZ(Vec3 v, double z)
{
    // Aquí pondríamos cualquier verificador de validez de datos, por ahora no tho
    v->z = z;
}


// Operaciones

double vec3_getMagnitude(Vec3 v)
{
    return ((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

Vec3 vec3_normalized(Vec3 v)
{
    double mag = vec3_getMagnitude(v);
    Vec3 res = vec3_create(v->x / mag, v->y / mag, v->z / mag);

    return res;
}

double vec3_point_product(Vec3 v1, Vec3 v2)
{
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

void vec3_print(Vec3 v)
{
    printf("=== Sobre el Vector ===\n");
    printf("(%.2lf, %.2lf, %.2lf)\n", v->x, v->y, v->z);
}
