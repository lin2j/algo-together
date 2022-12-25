//
// Created by Kenny on 2022/8/24.
//

#ifndef LEETCODE_C_PRIORITY_QUEUE_H
#define LEETCODE_C_PRIORITY_QUEUE_H

#include <stdbool.h>

typedef struct {
    int capacity;
    int size;
    int *data;
} t_priority_queue;

typedef t_priority_queue *PriorityQueue;

PriorityQueue new_priority_queue(int capacity);

void pq_free(PriorityQueue queue);

void pq_offer(PriorityQueue queue, int e);

bool pq_poll(PriorityQueue queue, int *e);

bool pq_peek(PriorityQueue queue, int *e);

void pq_print(PriorityQueue queue);

#endif //LEETCODE_C_PRIORITY_QUEUE_H
