#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
#include "queue.h"

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = NULL;
}

node_t* insert_recursive(node_t* root, node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(root->key_ > temp->key_)
	{
		root->left_ = insert_recursive(root->left_, temp);
	}
	else
	{
		root->right_ = insert_recursive(root->right_, temp);
	}
	return root;
}
void insert(tree_t *ptr_tree, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->left_ = temp->right_ = NULL;
	ptr_tree->root_ = insert_recursive(ptr_tree->root_, temp);
}

void levelorder_recursive(queue_t *q)
{
    if (is_empty(q))
	{
        return;
	}

    node_t *node = dequeue(q);
    printf("%d ", node->key_);

    if (node->left_ != NULL)
        enqueue(q, node->left_);
    if (node->right_ != NULL)
        enqueue(q, node->right_);

    levelorder_recursive(q);
}

void levelorder(tree_t *ptr_tree)
{
    queue_t q;
    init_q(&q);

    if (ptr_tree->root_ != NULL)
	{
        enqueue(&q, ptr_tree->root_);
	}

    levelorder_recursive(&q); printf("\n\n");
}

void levelorder_recursive_lines(queue_t *q, int level, int count)
{
    if (count == 0)
        return;

    printf("Level %d :  ", level);
    int next_count = 0;

    for (int i = 0; i < count; i++)
    {
        node_t *node = dequeue(q);
        if (node == NULL)
            return;
        printf("%d ", node->key_);
        if (node->left_ != NULL)
        {
            enqueue(q, node->left_);
            next_count++;
        }
        if (node->right_ != NULL)
        {
            enqueue(q, node->right_);
            next_count++;
        }
    }
    printf("\n");
    levelorder_recursive_lines(q, level + 1, next_count);
}

void levelorder_lines(tree_t *ptr_tree)
{
    queue_t q;
    init_q(&q);

    if (ptr_tree->root_ == NULL)
        return;

    enqueue(&q, ptr_tree->root_);
    levelorder_recursive_lines(&q, 0, 1);
}

void inorder_recursive(node_t* temp)
{
		if(temp)
		{
			inorder_recursive(temp->left_);
			printf("%d ", temp->key_);
			inorder_recursive(temp->right_);
		}
		
}

void inorder(tree_t *ptr_tree)
{
	inorder_recursive(ptr_tree->root_); printf("\n\n");
}
void preorder_recursive(node_t* temp)
{
		if(temp)
		{
			printf("%d ", temp->key_);
			preorder_recursive(temp->left_);
			preorder_recursive(temp->right_);
		}
}

void preorder(tree_t *ptr_tree)
{
	preorder_recursive(ptr_tree->root_); printf("\n\n");
}

void postorder_recursive(node_t* temp)
{
		if(temp)
		{
			postorder_recursive(temp->left_);
			postorder_recursive(temp->right_);
			printf("%d ", temp->key_);
		}
		
}

void postorder(tree_t *ptr_tree)
{
	postorder_recursive(ptr_tree->root_); printf("\n\n");
}


int count_nodes_recursive(node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else 
	{
		return 1 + count_nodes_recursive(root->left_) + 
			count_nodes_recursive(root->right_);
	}
}

int count_nodes(tree_t *ptr_tree)
{
	return count_nodes_recursive(ptr_tree->root_);
}

int count_leaves_recursive(node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else if(root->left_ == NULL && root->right_ == NULL)
	{
		return 1;
	}
	else 
	{
		return count_leaves_recursive(root->left_) + 
			count_leaves_recursive(root->right_);
	}
}

int count_leaves(tree_t *ptr_tree)
{
	return count_leaves_recursive(ptr_tree->root_);
}

int are_same_recursive(node_t* root1, node_t* root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return 1;
	}
	else if(root1 == NULL || root2 == NULL)
	{
		return 0;
	}
	else 
	{
		return root1->key_ == root2->key_ &&
			are_same_recursive(root1->left_, root2->left_) &&
			are_same_recursive(root1->right_, root2->right_);
		
	}
}

int are_same(tree_t *ptr_tree1, tree_t *ptr_tree2)
{
	return are_same_recursive(ptr_tree1->root_, ptr_tree2->root_);
}

node_t* copy_recursive(node_t* root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else 
	{
		node_t* temp = (node_t*)malloc(sizeof(node_t));
		temp->key_ = root->key_;
		temp->left_ = copy_recursive(root->left_);
		temp->right_ = copy_recursive(root->right_);
		return temp;
	}
		
}
void copy(tree_t* ptr_src, tree_t* ptr_dst)
{
	ptr_dst->root_ = copy_recursive(ptr_src->root_);
}
node_t* inorder_successor(node_t* root)
{
	// 1. one step to the right 
	node_t* temp = root->right_;
	// 2. move left until no more left 
	while(temp->left_ != NULL)
	{
		temp = temp->left_;
	}
	return temp;
}
node_t* delete_key_recursive(node_t* root, int key)
{
	// locate the key
	// 1. empty tree 
	if(root == NULL)
	{
		return NULL;
	}
	// 2. in left subtree?
	else if(key < root->key_)
	{
		root->left_ = delete_key_recursive(root->left_, key);
	}
	// 3. in right subtree?
	else if(key > root->key_)
	{
		root->right_ = delete_key_recursive(root->right_, key);
	}
	// 4. key found
	else 
	{
		// 1. leaf 
		if(root->left_ == NULL && root->right_ == NULL)
		{
			free(root);
			return NULL;
		}
		// 2. no left subtree 
		else if(root->left_ == NULL)
		{
			node_t* temp = root->right_;
			free(root);
			return temp;
		}
		// 3. no right subtree
		else if(root->right_ == NULL)
		{
			node_t* temp = root->left_;
			free(root);
			return temp;
		}
		// 4. has both left and right subtrees
		else 
		{
			// find the inorder successor
			node_t* temp = inorder_successor(root);
			// replace root key 
			root->key_ = temp->key_;
			// delete temp->key_ in the right subtree 
			root->right_ = delete_key_recursive(root->right_, temp->key_);
			return root;
		}
	}
	return root;
}
void delete_key(tree_t *ptr_tree, int key)
{
	ptr_tree->root_ = delete_key_recursive(ptr_tree->root_, key);
}