#ifndef DEQUE_H
#define DEQUE_H

typedef struct dnode
{
    int data;

    struct dnode *prev;
    struct dnode *next;
} dnode_t;


typedef struct
{
    dnode_t *front;
    dnode_t *rear;
} deque_t;


// Deque functions
void dequeInit(deque_t *dq);

int dequeIsEmpty(deque_t *dq);

void insertFront(deque_t *dq, int value);

void insertRear(deque_t *dq, int value);

int deleteFront(deque_t *dq);

int deleteRear(deque_t *dq);

void dequeDisplay(deque_t *dq);

#endif