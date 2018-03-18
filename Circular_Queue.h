#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct _Node {
    int level;      /* The level of tree */
    int profit;
    int weight;
} Node;

typedef struct _Queue {
    int  front, rear;
    int  length;
    Node *data;
} Queue;

typedef struct _Queue_Algo {
    void (*Create)(Queue *, int);
    void (*Delete)(Queue);

    bool (*Is_Empty)(Queue);
    bool (*Is_Full)(Queue);

    void (*Enqueue)(Queue *, Node);
    void (*Dequeue)(Queue *, Node *);
} _Queue_Algo;

extern bool queue_flag;

extern _Queue_Algo Queue_Algo;

#endif /* CIRCULAR_QUEUE_H_ */
