#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main()
{
	int n;

    // -----1st Polynomial-----
    printf("1st Polynomial: \n");
    printf("Enter number of terms: ");  scanf("%d",&n);
    int coeff[n], expo[n];

    printf("Enter each term: \n");
    for(int i = 0; i < n; ++i)
	{
		printf("%d. ",(i+1));   scanf("%d %d",&coeff[i],&expo[i]);
	}

	poly_t mypoly;
	init_poly(&mypoly);
	for(int i = 0; i < n; ++i)
	{
		insert(&mypoly, coeff[i], expo[i]);
	}
	disp(&mypoly);



    // -----2nd Polynomial-----
    printf("\n\n2nd Polynomial: \n");
    printf("Enter number of terms: ");  scanf("%d",&n);
    int coeff2[n], expo2[n];

    printf("Enter each term: \n");
    for(int i = 0; i < n; ++i)
	{
		printf("%d. ",(i+1));   scanf("%d %d",&coeff2[i],&expo2[i]);
	}

	poly_t mypoly2;
	init_poly(&mypoly2);
	for(int i = 0; i < n; ++i)
	{
		insert(&mypoly2, coeff2[i], expo2[i]);
	}
	disp(&mypoly2);


    //----- Adding -----

    poly_t mypolyF;
	init_poly(&mypolyF);

    add_poly(&mypolyF, &mypoly, &mypoly2);
    disp(&mypolyF);

}