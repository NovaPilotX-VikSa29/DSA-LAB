#include <stdio.h>
#include "mylist.h"
#include "rect.h"

int main()
{
	mylist_t list;
    rect_t rectangle;
	init_list(&list);

    int n;
    printf("Enter number of inputs: "); scanf("%d",&n);

    int l[n],b[n];

    for(int i = 0; i < n; ++i)
    {
        printf("%d. ",i+1);
        scanf("%d %d",&l[i],&b[i]);
    }

	for(int i = 0; i < n; ++i)
	{
		set_rect(&rectangle,l[i],b[i]);
        printf("Area of %d. = %.2f \n", i+1, area_rect(&rectangle));
        insert_list(&list,rectangle);
	}
	disp_list(&list);
	free_list(&list);
}