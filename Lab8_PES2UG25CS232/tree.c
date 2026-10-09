#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = -1;
	ptr_tree->count_ = 0;

	init_stack(&ptr_tree->stack_);

	for (int i = 0; i < MAXSIZE; i++)
    {
        push(&ptr_tree->stack_, i);
    }
}

int insert_recursive(node_t elem[], int root, int temp)
{
	if(root == -1)
	{
		root = temp;
	}
	else if(elem[root].key_ > elem[temp].key_)
	{
		elem[root].left_ = insert_recursive(elem, elem[root].left_, temp);
	}
	else
	{
		elem[root].right_ = insert_recursive(elem, elem[root].right_, temp);
	}
	return root;
}

void insert(tree_t *ptr_tree, int key)
{
	if (is_empty(&ptr_tree->stack_))
    {
        printf("Stack empty. Cannot insert.\n");
        return;
    }
	int temp = pop(&ptr_tree->stack_);
	ptr_tree->elem_[temp].key_ = key;
	ptr_tree->elem_[temp].left_ = ptr_tree->elem_[temp].right_ = -1;
	ptr_tree->root_ = insert_recursive(ptr_tree->elem_, ptr_tree->root_, temp);
}

int inorder_successor(node_t elem_[], int root)
{
    int temp = elem_[root].right_;

    while (elem_[temp].left_ != -1)
    {
        temp = elem_[temp].left_;
    }

    return temp;
}


int delete_key_recursive(node_t elem[], int root, int key, stack_t *stack)
{
    if (root == -1)
    {
        return -1;
    }

    else if (key < elem[root].key_)
    {
        elem[root].left_ = delete_key_recursive(elem,elem[root].left_,key,stack);
    }

    else if (key > elem[root].key_)
    {
        elem[root].right_ = delete_key_recursive(elem,elem[root].right_,key,stack);
    }

    else
    {
        if (elem[root].left_ == -1 && elem[root].right_ == -1)
        {
            push(stack, root);
            return -1;
        }

        else if (elem[root].left_ == -1)
        {
            int temp = elem[root].right_;
            push(stack, root);
            return temp;
        }

        else if (elem[root].right_ == -1)
        {
            int temp = elem[root].left_;
            push(stack, root);
            return temp;
        }

        else
        {
            int temp = inorder_successor(elem, root);
            elem[root].key_ = elem[temp].key_;
            elem[root].right_ = delete_key_recursive(elem,elem[root].right_,elem[temp].key_,stack);

            return root;
        }
    }

    return root;
}


void delete_key(tree_t *ptr_tree, int key)
{
    ptr_tree->root_ = delete_key_recursive(ptr_tree->elem_,ptr_tree->root_,key,&ptr_tree->stack_);
}

void disp_recursive(node_t elem[], int temp)
{
		if(temp != -1)
		{
			disp_recursive(elem, elem[temp].left_);
			printf("%d ", elem[temp].key_);
			disp_recursive(elem, elem[temp].right_);
		}
		
}

void disp(tree_t *ptr_tree)
{
	disp_recursive(ptr_tree->elem_, ptr_tree->root_); 
	printf("\n\n");
}