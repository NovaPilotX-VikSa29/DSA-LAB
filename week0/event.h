#ifndef EVENT_H
#define EVENT_H
#include "date.h"
struct event 
{
	char detail_[20];
	date_t date_;
};
typedef struct event event_t;
void set_event(event_t* ptr_event, char* detail, int dd,
	int mm, int yy);
void disp_event(event_t* ptr_event);
#endif