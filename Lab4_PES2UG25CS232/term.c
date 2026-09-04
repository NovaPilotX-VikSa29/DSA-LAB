#include <stdio.h>
#include "term.h"


// use int coeff for addition and double coeff for integration
void set_term(term_t* ptr_term, double coeff, int expo) 
{
	ptr_term->coeff_ = coeff;
	ptr_term->expo_ = expo;
}

void disp_term(term_t* ptr_term)
{
	printf("(%.1lf)x^%d\t", ptr_term->coeff_, ptr_term->expo_);
}

int compare_exponents(term_t* left, term_t* right)
{
	return left->expo_ - right->expo_;
}




// Below extra is for integration
void integrate_term(term_t* ptr_term, term_t* ptr_integrated_term)
{
	if(ptr_term->expo_ == -1)
	{
		printf("Error: Cannot integrate x^-1 using the power rule.\n");
		set_term(ptr_integrated_term, 0, 0);
		return;
	}

	ptr_integrated_term->coeff_ =
		ptr_term->coeff_ / (ptr_term->expo_ + 1);

	ptr_integrated_term->expo_ =
		ptr_term->expo_ + 1;
}