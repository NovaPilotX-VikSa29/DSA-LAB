#ifndef MYLIST_H
#define MYLIST_H

#include "rect.h"
struct node
{
	rect_t rectangle;
	struct node *next_;
};
typedef struct node node_t;


struct mylist
{
	node_t *head_;
};
typedef struct mylist mylist_t;

void init_list(mylist_t*);
void insert_list(mylist_t*, rect_t rectangle);
void disp_list(mylist_t*);
void free_list(mylist_t*);

#endif