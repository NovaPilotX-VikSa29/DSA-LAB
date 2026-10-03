#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"

void initDeque(Deque *dq, int size)
{
    dq->arr = (Node *)malloc(sizeof(Node) * size);
    dq->front = 0;
    dq->rear = -1;
    dq->size = size;
}

int isEmpty(Deque *dq)
{
    return dq->front > dq->rear;
}

void pushBack(Deque *dq, int value, int index)
{
    dq->rear++;
    dq->arr[dq->rear].value = value;
    dq->arr[dq->rear].index = index;
}

void popBack(Deque *dq)
{
    if (!isEmpty(dq))
        dq->rear--;
}

void popFront(Deque *dq)
{
    if (!isEmpty(dq))
        dq->front++;
}

Node getFront(Deque *dq)
{
    return dq->arr[dq->front];
}

Node getBack(Deque *dq)
{
    return dq->arr[dq->rear];
}

void freeDeque(Deque *dq)
{
    free(dq->arr);
}