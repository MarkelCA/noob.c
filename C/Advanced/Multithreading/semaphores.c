#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct process {
    // Define process attributes here
};

struct semaphore {
    struct process q[MAX_QUEUE_SIZE];
    int front, rear;
    int value;
};

void P(struct semaphore *s) {
    if (s->value == 1) {
        s->value = 0;
    } else {
        // Push the process to the queue and sleep
        // Implement sleep here
    }
}

void V(struct semaphore *s) {
    if (s->front == s->rear) {
        s->value = 1;
    } else {
        // Get a process from the queue
        struct process *p = &s->q[s->front];
        s->front = (s->front + 1) % MAX_QUEUE_SIZE; // Circular queue
        // Implement wakeup here
    }
}

int main() {
    printf("This is Hemish!!");
    return 0;
}

