#ifndef COMMON_H_
#define COMMON_H_

typedef void* Type;
typedef enum {False, True} Bool;
typedef void(*PrintFunc)(Type);
typedef void(*DestroyFunc)(Type);
typedef int(*CompareFunc)(Type, Type);

#endif
