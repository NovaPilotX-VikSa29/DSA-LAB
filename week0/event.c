#include <stdio.h>
#include "event.h"
#include <string.h>

void set_event(event_t* ptr_event, char* detail, int dd,
	int mm, int yy)
{
	strcpy(ptr_event->detail_, detail);
	set_date(&ptr_event->date_, dd, mm, yy);
	
}

void disp_event(event_t* ptr_event)
{
	printf("detail : %s\n", ptr_event->detail_);
	disp_date(&ptr_event->date_);
}