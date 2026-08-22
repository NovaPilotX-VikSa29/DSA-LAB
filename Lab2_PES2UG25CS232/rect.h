#ifndef RECT_H
#define RECT_H

struct rect
{
	double length;
	double breadth;
};
typedef struct rect rect_t;

void set_rect(rect_t *r, double length, double breadth);
void disp_rect(rect_t *r);
double area_rect(rect_t *r);
int compare_rect(rect_t *a, rect_t *b);

#endif