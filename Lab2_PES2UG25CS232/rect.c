#include "rect.h"
#include <stdio.h>

void set_rect(rect_t *r, double length, double breadth)
{
    r->length = length;
    r->breadth = breadth; 
}
void disp_rect(rect_t *r)
{
    printf("length= %f, bredth= %f \n",r->length,r->breadth);
}

double area_rect(rect_t *r)
{
    return r->length * r->breadth;
}

int compare_rect(rect_t *a, rect_t *b)
{
    double area_a = area_rect(a);
    double area_b = area_rect(b);
    if (area_a < area_b)
        return 1; // a is smaller
    else
        return 0;
}