#ifndef QUEUE_H
#define QUEUE_H

struct node_s {
    int key_;
    struct node_s* next_;
};
typedef struct node_s node_t;

struct queue_s {
    node_t *front_;
    node_t *rear_;
};
typedef struct queue_s queue_t;

void init_queue(queue_t *ptr_queue);
void deinit_queue(queue_t *ptr_queue);
void enqueue(queue_t *ptr_queue, int key);
int dequeue(queue_t *ptr_queue);
int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

#endif