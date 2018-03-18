#include <stdio.h>
#include <stdlib.h>
#include "Circular_Queue.h"

bool queue_flag = false;

static void Create(Queue *queue, int length)
{
    queue->front  = 0;
    queue->rear   = 0;
    queue->length = length;
    queue->data   = (Node *) calloc(length, sizeof(Node));
}

static void Delete(Queue queue)
{
    free(queue.data);
}

static bool Is_Empty(Queue q)
{
    return (q.front == q.rear);
}

static bool Is_Full(Queue q)
{
    return (q.front == (q.rear % q.length));
}

static void Enqueue(Queue *q, Node node)
{
    if (Is_Full(*q) && queue_flag == 1) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % q->length;
    q->data[q->rear] = node;

    if (q->front == q->rear) queue_flag = 1;
}

static void Dequeue(Queue *q, Node *node)
{
    if (Is_Empty(*q) && queue_flag == 0) {
        printf("Queue is empty!\n");
        return;
    }

    q->front = (q->front + 1) % q->length;
    *node = q->data[q->front];

    if (q->front == q->rear) queue_flag = 0;
}

_Queue_Algo Queue_Algo = {
    .Create   = Create,
    .Delete   = Delete,

    .Is_Empty = Is_Empty,
    .Is_Full  = Is_Full,
    .Enqueue  = Enqueue,
    .Dequeue  = Dequeue,
};
