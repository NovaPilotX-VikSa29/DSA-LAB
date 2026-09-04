#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void init_poly(poly_t *ptr_poly)
{
	ptr_poly->head_ = NULL;
}

void disp(poly_t *ptr_poly)
{
	node_t* pres = ptr_poly->head_;
	while(pres != NULL)
	{
		//printf("%d ", pres->key_);
		disp_term(&pres->term_);
		pres = pres->next_;
	}
	printf("\n");
}

void insert(poly_t* ptr_poly, int coeff, int expo) 
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	set_term(&temp->term_, coeff, expo);
	temp->next_ = NULL;
	
	// 1. empty poly 
	if(ptr_poly->head_ == NULL)
	{
		ptr_poly->head_ = temp;
		temp->next_ = NULL;
	}
	else // find the position
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_poly->head_;
		//while(pres != NULL && pres->key_ < temp->key_)
		while(pres != NULL && 
			compare_exponents(&pres->term_, &temp->term_) > 0)
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			ptr_poly->head_ = temp;
			temp->next_ = pres;
		}
		else // middle or end 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
	
}

void add_poly(poly_t* ptr_poly, poly_t* ptr_poly_1, poly_t* ptr_poly_2)
{
    node_t *p1 = ptr_poly_1->head_;
    node_t *p2 = ptr_poly_2->head_;

    init_poly(ptr_poly);

    while(p1 != NULL && p2 != NULL)
    {
        int result = compare_exponents(&p1->term_, &p2->term_);

        if(result > 0)
        {
            insert(ptr_poly,
                   p1->term_.coeff_,
                   p1->term_.expo_);

            p1 = p1->next_;
        }
        else if(result < 0)
        {
            insert(ptr_poly,
                   p2->term_.coeff_,
                   p2->term_.expo_);

            p2 = p2->next_;
        }
        else
        {
            int coeff = p1->term_.coeff_ + p2->term_.coeff_;

            if(coeff != 0)
            {
                insert(ptr_poly,
                       coeff,
                       p1->term_.expo_);
            }

            p1 = p1->next_;
            p2 = p2->next_;
        }
    }

    while(p1 != NULL)
    {
        insert(ptr_poly,
               p1->term_.coeff_,
               p1->term_.expo_);

        p1 = p1->next_;
    }

    while(p2 != NULL)
    {
        insert(ptr_poly,
               p2->term_.coeff_,
               p2->term_.expo_);

        p2 = p2->next_;
    }
}