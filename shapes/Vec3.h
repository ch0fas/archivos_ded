#ifndef VEC3_H_
#define VEC3_H_ // Si no está definido VEC3_H_, lo define, esta convención hace que no hayan archivos repetidos
// Todo se define adentro de este "if"

typedef struct strVec3* Vec3;

Vec3 vec3_create(double x, double y, double z);
void vec3_destroy(Vec3);

double vec3_getX(Vec3);
void vec3_setX(Vec3, double);

double vec3_getY(Vec3);
void vec3_setY(Vec3, double);

double vec3_getz(Vec3);
void vec3_setz(Vec3, double);

double vec3_getMagnitude(Vec3);
Vec3 vec3_normalized(Vec3);
double vec3_point_product(Vec3, Vec3);
void vec3_print(Vec3);
bool vec3_equals(Vec3, Vec3);
Vec3 vec3_clone(Vec3);

#endif
