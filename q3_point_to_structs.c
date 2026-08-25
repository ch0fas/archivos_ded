#include <stdio.h>

typedef struct
{
    unsigned char red, green, blue;
} Color;

void changeColor(Color *pc)
{
    // pc[0].red = 255 - pc[0].red;
    (*pc).red = 255 - (*pc).red;
}

int main()
{
    Color c = {50,60,70};
    changeColor(&c);
    printf("%d %d %d", c.red, c.green, c.blue);
    return 0;
}