#include <stdio.h>
#include "tree.h"

int main()
{
    int a1[] = {40, 60, 20, 10, 30, 70, 50};
	int n1 = 7;

	tree_t t1;
	init(&t1);

	for(int i = 0; i < n1; ++i)
	{
		insert(&t1, a1[i]);
	}
	
	printf("tree inorder : ");
	inorder(&t1);

    printf("\ntree level order : ");
	levelorder(&t1);

    printf("\ntree level order : \n");
	levelorder_lines(&t1);
}