#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_q(queue_t *ptr_queue)
{
	ptr_queue->front_ = ptr_queue->rear_ = ptr_queue->count_ = 0;
}

void deinit_q(queue_t *ptr_queue)
{
	// no resources 
	ptr_queue->front_ = ptr_queue->rear_ = 0;
}


// critical cases :
// 1, empty 
// 2. some nodes
void enqueue(queue_t *ptr_queue, node_t* key)
{
	  ptr_queue->rear_  = (ptr_queue->rear_ + 1) % MAXSIZE;
	  if(is_full(ptr_queue))
	  {
		  printf("queue full\n");
		  // reverse incr effect 
		  ptr_queue->rear_  = (ptr_queue->rear_ + MAXSIZE - 1) % MAXSIZE;
		  
	  }
	  else
	  {
		  ptr_queue->key_[ptr_queue->rear_] = key;
	  }
}


node_t* dequeue(queue_t *ptr_queue)
{
	if(is_empty(ptr_queue))
	{
		printf("queue empty\n");
		// what do we return?
		// assume keys are positive ;
		// return a negative value 
		exit(1);
	}
	else 
	{
		ptr_queue->front_ = (ptr_queue->front_ + 1) % MAXSIZE;
		return ptr_queue->key_[ptr_queue->front_];
	} 
	
}

// checked in dequeue before incrementing front 
int is_empty(queue_t *ptr_queue)
{
	return ptr_queue->front_ == ptr_queue->rear_;
}

// checked in enqueue after incrementing rear 
int is_full(queue_t *ptr_queue)
{
	return ptr_queue->front_ == ptr_queue->rear_;
}