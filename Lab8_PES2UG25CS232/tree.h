#ifndef TREE_H
#define TREE_H
#define MAXSIZE 5

#include "stack.h"

struct node
{
	int key_;
	int left_;
	int right_;
};
typedef struct node node_t;

struct tree 
{
	int root_; // -1 on empty
	int count_; // # of elem 
	node_t elem_[MAXSIZE];

	stack_t stack_;
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void delete_key(tree_t *ptr_tree, int key);
void disp(tree_t *ptr_tree);

#endif