#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

#define MAXSIZE 5
struct queue
{
	node_t* key_[MAXSIZE];
	// indices
	int count_;
	int front_;
	int rear_;
};
typedef struct queue queue_t;

void init_q(queue_t *ptr_queue);
void deinit_q(queue_t *ptr_queue);
void enqueue(queue_t *ptr_queue, node_t* key);
node_t* dequeue(queue_t *ptr_queue);

int is_empty(queue_t *ptr_queue);
int is_full(queue_t *ptr_queue);

#endif