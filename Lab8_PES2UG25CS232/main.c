#include <stdio.h>
#include "tree.h"

int main()
{
    tree_t tree;
    int opt, key;

    init(&tree);

    printf("1 : insert;  2 : display;  3 : delete;  0 : exit\n");
    scanf("%d", &opt);

    while (opt)
    {
        switch (opt)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(&tree, key);
                break;

            case 2:
                printf("Inorder traversal: ");
                disp(&tree);
                printf("\n");
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_key(&tree, key);
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\n1 : insert;  2 : display;  3 : delete;  0 : exit\n");
        scanf("%d", &opt);
    }

    return 0;
}