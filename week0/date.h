#ifndef DATE_H
#define DATE_H 
struct date 
{
	int dd_;
	int mm_;
	int yy_;
};
typedef struct date date_t;
void set_date(date_t* ptr_date, int dd, int mm, int yy);
void disp_date(date_t* ptr_date);
#endif