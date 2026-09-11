#include <stdio.h> 
#include "clist.h" 
int main() 
{ 
	clist_t list; 
	int n, k; 
	int i; 
	init_clist(&list); 
	printf("Enter number of people: "); 
	scanf("%d", &n); if (n < 1) 
	{ 
		printf("Invalid value of n\n"); 
		return 1; 
	} 
	
	printf("Enter the count k to be removed: "); scanf("%d", &k); 
	
	if (k < 1) 
	{ 
		printf("Invalid value of k\n"); 
		return 1; 
	}  
	
	for (i = 1; i <= n; i++) 
	{ 
		char name_temp[50]; 
		printf("Enter name: "); 
		scanf("%49s", name_temp); 
		add(&list, i, name_temp); 
	} 
	
	printf("\nInitial list:\n"); 
	disp(&list); 
	printf("\nElimination order:\n"); 
	/* current points to the node before the first node to be removed. */ 
	
	node_t *current = list.head_; 
	
	while (current->next_ != list.head_) 
	{ 
		
		current = current->next_; 
	} 
	
	for (i = 1; i < n; i++) 
	{ 
		int j; 
		/* move to the node before the kth node */ 
		for (j = 1; j < k; j++) 
		{ 
			current = current->next_; 
		} 
		node_t *removed = current->next_; 
		printf("%d %s\n", removed->key_, removed->name_); 
		delete(current); 
		list.head_ = current->next_; 
	} 
	printf("\nSurvivor:\n"); 
	disp(&list); 
	deinit(&list); 
	return 0; 
}