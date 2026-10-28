#ifndef TREE_H
#define TREE_H
struct node
{
	int key_;
	struct node *left_;
	struct node *right_;
};
typedef struct node node_t;

struct tree 
{
	node_t* root_;
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);

void inorder(tree_t *ptr_tree);
void preorder(tree_t *ptr_tree);
void postorder(tree_t *ptr_tree);
void levelorder(tree_t *ptr_tree);
void levelorder_lines(tree_t *ptr_tree);

int count_nodes(tree_t *ptr_tree);
int count_leaves(tree_t *ptr_tree);

int are_same(tree_t *ptr_tree1, tree_t *ptr_tree2);
void copy(tree_t* ptr_src, tree_t* ptr_dst);

void delete_key(tree_t *ptr_tree, int key);
#endif