#include "queue.h"


void queueInit(queue_t *q)
{
    dequeInit(&q->deque);
}


int queueIsEmpty(queue_t *q)
{
    return dequeIsEmpty(&q->deque);
}


void queueEnqueue(queue_t *q, int value)
{
    insertRear(&q->deque, value);
}


int queueDequeue(queue_t *q)
{
    return deleteFront(&q->deque);
}


void queueDisplay(queue_t *q)
{
    dequeDisplay(&q->deque);
}