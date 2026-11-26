#ifndef COMMON_H_
#define COMMON_H_

typedef void* Type;
typedef enum {False, True} Bool;
typedef void (*DestroyFunc)(Type);
typedef int  (*CompareFunc)(Type, Type);
typedef void (*PrintFunc)(Type);

#endif
