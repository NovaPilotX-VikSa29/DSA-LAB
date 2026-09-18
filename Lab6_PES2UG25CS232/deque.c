#include <stdio.h>
#include <stdlib.h>
#include "deque.h"


void dequeInit(deque_t *dq)
{
    dq->front = NULL;
    dq->rear = NULL;
}


int dequeIsEmpty(deque_t *dq)
{
    return dq->front == NULL;
}


void insertFront(deque_t *dq, int value)
{
    dnode_t *new_node;

    new_node = (dnode_t *)malloc(sizeof(dnode_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = dq->front;


    // Empty deque
    if (dq->front == NULL)
    {
        dq->front = new_node;
        dq->rear = new_node;
    }
    else
    {
        dq->front->prev = new_node;
        dq->front = new_node;
    }
}


void insertRear(deque_t *dq, int value)
{
    dnode_t *new_node;

    new_node = (dnode_t *)malloc(sizeof(dnode_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = dq->rear;


    // Empty deque
    if (dq->rear == NULL)
    {
        dq->front = new_node;
        dq->rear = new_node;
    }
    else
    {
        dq->rear->next = new_node;
        dq->rear = new_node;
    }
}


int deleteFront(deque_t *dq)
{
    dnode_t *temp;
    int value;

    if (dq->front == NULL)
    {
        printf("Deque is empty.\n");
        return -1;
    }

    temp = dq->front;
    value = temp->data;


    // Only one node
    if (dq->front == dq->rear)
    {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else
    {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);

    return value;
}


int deleteRear(deque_t *dq)
{
    dnode_t *temp;
    int value;

    if (dq->rear == NULL)
    {
        printf("Deque is empty.\n");
        return -1;
    }

    temp = dq->rear;
    value = temp->data;


    // Only one node
    if (dq->front == dq->rear)
    {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else
    {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);

    return value;
}


void dequeDisplay(deque_t *dq)
{
    dnode_t *pres;

    if (dq->front == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Front -> ");

    pres = dq->front;

    while (pres != NULL)
    {
        printf("%d ", pres->data);
        pres = pres->next;
    }

    printf("<- Rear\n");
}