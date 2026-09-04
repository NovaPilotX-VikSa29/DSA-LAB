#ifndef POLY_H
#define POLY_H
#include "term.h"
// user: list of terms
struct node 
{
	term_t term_;
	struct node *next_;
};
typedef struct node node_t;

struct poly 
{
	node_t* head_;
};
typedef struct poly poly_t;

void init_poly(poly_t* ptr_poly);
void insert(poly_t* ptr_poly, double coeff, int expo);
// for above function, use int coeff for addition and double coeff for integration
void disp(poly_t* ptr_list);
void add_poly(poly_t* ptr_poly,poly_t* ptr_poly_1,poly_t* ptr_poly_2);

// below extra is for integration
poly_t integrate_poly(poly_t poly);
double eval_poly(poly_t poly, double x);
void destroy_poly(poly_t* ptr_poly);
poly_t create_poly(void);

#endif