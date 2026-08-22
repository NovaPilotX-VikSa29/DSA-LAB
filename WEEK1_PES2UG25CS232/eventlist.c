#include <stdio.h>
#include "event.h"
#include "date.h"
#include "eventlist.h"

int read_all(FILE *fp, event_t e[], int n)
{
    int count = 0;
    while(count < n && !feof(fp))
    {
        read_event(fp, &e[count]);
        count++;
    }
    return count;
}

void disp_all(event_t e[], int n)
{
    for(int i = 0; i<n; i++)
    {
        print_event(e[i]);
        printf("\n");
    }
}

event_t find_latest(event_t e[], int n)
{
    event_t latest = e[0];
    for(int i = 1; i<n; i++)
    {
        if(compare_date(e[i].d, latest.d) > 0)
        {
            latest = e[i];
        }
    }
    return latest;
}

int count_in_month(event_t e[], int n, int month)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(e[i].d.mm == month)
        {
            count++;
        }
    }
    return count;
}