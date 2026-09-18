#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"


void init_pqueue(pqueue_t *pq)
{
    pq->front = NULL;
}


int is_empty(pqueue_t *pq)
{
    return pq->front == NULL;
}


void enqueue(pqueue_t *pq, int job_id, int depth, int traffic)
{
    node_t *new_node;
    node_t *pres;

    new_node = (node_t *)malloc(sizeof(node_t));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->job_id = job_id;
    new_node->depth = depth;
    new_node->traffic = traffic;
    new_node->priority = depth + traffic;
    new_node->next = NULL;


    // Case 1: Empty queue
    if (pq->front == NULL)
    {
        pq->front = new_node;
        return;
    }


    // Case 2: New node has higher priority than front
    if (new_node->priority > pq->front->priority)
    {
        new_node->next = pq->front;
        pq->front = new_node;
        return;
    }


    // Case 3: Find correct position
    pres = pq->front;

    while (pres->next != NULL &&
           pres->next->priority >= new_node->priority)
    {
        pres = pres->next;
    }

    new_node->next = pres->next;
    pres->next = new_node;
}


int dequeue(pqueue_t *pq)
{
    node_t *temp;
    int job_id;

    if (pq->front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    temp = pq->front;

    job_id = temp->job_id;

    printf("Processing Job %d (Depth=%d, Traffic=%d, Priority=%d)\n",
           temp->job_id,
           temp->depth,
           temp->traffic,
           temp->priority);

    pq->front = pq->front->next;

    free(temp);

    return job_id;
}


void display(pqueue_t *pq)
{
    node_t *pres;

    if (pq->front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nJobID\tDepth\tTraffic\tPriority\n");
    printf("---------------------------------------\n");

    pres = pq->front;

    while (pres != NULL)
    {
        printf("%d\t%d\t%d\t%d\n",
               pres->job_id,
               pres->depth,
               pres->traffic,
               pres->priority);

        pres = pres->next;
    }
}