#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"

void init_clist(clist_t *ptr_clist)
{
    ptr_clist->head_ = NULL;
}

void add(clist_t *ptr_clist, int key, char name[50])
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->key_ = key;
    strcpy(temp->name_, name);

    if (ptr_clist->head_ == NULL)
    {
        ptr_clist->head_ = temp;
        temp->next_ = temp;
    }
    else
    {
        temp->next_ = ptr_clist->head_->next_;
        ptr_clist->head_->next_ = temp;
    }
}

void disp(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->head_;

    if (pres == NULL)
    {
        printf("empty clist\n");
        return;
    }

    do
    {
        printf("%d %s\n", pres->key_, pres->name_);
        pres = pres->next_;
    }
    while (pres != ptr_clist->head_);

    printf("\n");
}

void deinit(clist_t *ptr_clist)
{
    if (ptr_clist->head_ == NULL)
        return;

    while (ptr_clist->head_->next_ != ptr_clist->head_)
    {
        node_t *temp = ptr_clist->head_->next_;
        ptr_clist->head_->next_ = temp->next_;
        free(temp);
    }

    free(ptr_clist->head_);
    ptr_clist->head_ = NULL;
}


int delete(node_t *current)
{
    if (current == NULL)
        return -1;

    if (current->next_ == current)
        return -1;

    node_t *temp = current->next_;
    current->next_ = temp->next_;

    free(temp);

    return 0;
}

int find_kth(clist_t* ptr_list, int k)
{
    if(ptr_list->head_ == NULL || k <= 0)
    {
        printf("Invalid input\n");
        return -1;
    }

    for(int i = 1; i < k; ++i)
    {
        ptr_list->head_ = ptr_list->head_->next_;
    }

    printf("The %d-th node is: %d %s\n", k, ptr_list->head_->key_, ptr_list->head_->name_);
    return 0;
}