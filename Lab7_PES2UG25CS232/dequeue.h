#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    int value;
    int index;
} Node;

typedef struct {
    Node *arr;
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq, int size);
int isEmpty(Deque *dq);
void pushBack(Deque *dq, int value, int index);
void popBack(Deque *dq);
void popFront(Deque *dq);
Node getFront(Deque *dq);
Node getBack(Deque *dq);
void freeDeque(Deque *dq);

#endif