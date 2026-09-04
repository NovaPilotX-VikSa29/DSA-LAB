#ifndef TERM_H
#define TERM_H
struct term
{
	double coeff_; // for  addition use int coeff_ and for integration use double coeff_
	int expo_;
};
typedef struct term term_t;

void set_term(term_t* ptr_term, double coeff, int expo_); 
// for above function, use int coeff for addition and double coeff for integration
void disp_term(term_t* ptr_term);
int compare_exponents(term_t* left, term_t* right);

// Below extra is for integration
void integrate_term(term_t* ptr_term, term_t* ptr_integrated_term);
#endif