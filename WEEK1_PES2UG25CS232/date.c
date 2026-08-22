#include <stdio.h>
#include "date.h"

#include <stdio.h>
#include "date.h"

date_t make_date(int dd, int mm, int yy)
{
    date_t d;

    d.dd = dd;
    d.mm = mm;
    d.yy = yy;

    return d;
}

void read_date(FILE *fp, date_t *d)
{
    fscanf(fp, "%d-%d-%d", &d->dd, &d->mm, &d->yy);
}

void print_date(date_t d)
{
    printf("%d-%d-%d", d.dd, d.mm, d.yy);
}

int compare_date(date_t d1, date_t d2)
{
    if (d1.yy < d2.yy)
        return -1;
    else if (d1.yy > d2.yy)
        return 1;
    else if (d1.mm < d2.mm)
        return -1;
    else if (d1.mm > d2.mm)
        return 1;
    else if (d1.dd < d2.dd)
        return -1;
    else if (d1.dd > d2.dd)
        return 1;

    return 0;
}