#include <stdio.h>
#include "rect.h"

int main()
{
    rect_t r;
    set_rect(&r, 10.0, 5.0);
    disp_rect(&r);
    printf("Area: %f\n", area_rect(&r));

    return 0;
}