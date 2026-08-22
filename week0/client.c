#include <stdio.h>
#include "event.h"

int main()
{
	event_t e;
	set_event(&e, "Earth Quake", 26, 01, 2001);
	disp_event(&e);
}