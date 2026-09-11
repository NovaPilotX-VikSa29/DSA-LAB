#ifndef CLIST_H
#define CLIST_H

struct node
{
    int key_;
    char name_[50];
    struct node* next_;
};

typedef struct node node_t;

struct clist
{
    node_t* head_;
};

typedef struct clist clist_t;

void init_clist(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key, char name[50]);
void disp(clist_t *ptr_clist);
void deinit(clist_t *ptr_clist);

int delete(node_t *current);
int find_kth(clist_t *ptr_clist, int k);

#endif