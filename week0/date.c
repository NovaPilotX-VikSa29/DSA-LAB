#include <stdio.h>
#include "date.h"

void set_date(date_t* ptr_date, int dd, int mm, int yy)
{
	ptr_date->dd_ = dd;
	ptr_date->mm_ = mm;
	ptr_date->yy_ = yy;
}

void disp_date(date_t* ptr_date)
{
	printf("date : %d-%d-%d\n", ptr_date->dd_, 
		ptr_date->mm_, ptr_date->yy_);
}