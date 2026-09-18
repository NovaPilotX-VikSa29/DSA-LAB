#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"


typedef struct
{
    deque_t deque;
} queue_t;


// Queue functions
void queueInit(queue_t *q);

int queueIsEmpty(queue_t *q);

void queueEnqueue(queue_t *q, int value);

int queueDequeue(queue_t *q);

void queueDisplay(queue_t *q);

#endif