#ifndef PQUEUE_H
#define PQUEUE_H

// Node representing one pothole repair job
typedef struct node
{
    int job_id;
    int depth;
    int traffic;
    int priority;

    struct node *next;
} node_t;


// Priority Queue structure
// Only front pointer is maintained
typedef struct
{
    node_t *front;
} pqueue_t;


// Function prototypes
void init_pqueue(pqueue_t *pq);

void enqueue(pqueue_t *pq, int job_id, int depth, int traffic);

int dequeue(pqueue_t *pq);

void display(pqueue_t *pq);

int is_empty(pqueue_t *pq);

#endif