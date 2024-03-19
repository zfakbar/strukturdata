#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int count;
    int items[];
}queue;

queue* new_queue(int size) {
    queue *q = malloc(sizeof(queue) + size*sizeof(int));

    q->front = 1;
    q->rear = 1;
    q->count = size;

    return q;
}

int is_empty(queue *q) {
    if(q->rear == q->front)
        return 1;
    return 0;
}

int is_full(queue *q) {
    if(q->front == q->rear+1)
        return 1;
    return 0;
}

void enqueue(queue *q, int x) {
    if(is_full(q)) {
        printf("Queue Penuh, Data tidak dapat disimpan\n");
    }
    else {
        q->items[q->rear] = x;
        if(q->front == q->count)
            q->rear = 1;
        else
            q->rear = q->rear+1;
    }
}

int dequeue(queue *q) {
    if(is_empty(q)) {
        printf("Queue Kosong, tidak dapat mengambil data\n");
        return -1000;
    }
    else {
        int x = q->items[q->front];
        if(q->front == q->count) {
            q->front = 1;
        }
        else {
            q->front = q->front+1;
        }     
        return x;
    }
}

void display(queue *q) {
    int i;
    for(i=q->front; i<q->rear; i++) {
        printf("%d ",q->items[i]);
        if(i == q->count) {
            i = 0;
        }
    }
    printf("\n");
}

int main() {
    queue *q = new_queue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    printf("\n");

    dequeue(q);
    dequeue(q);
    display(q);

    printf("\n");

    enqueue(q, 60);
    enqueue(q, 70);
    display(q);
    return 0;
}