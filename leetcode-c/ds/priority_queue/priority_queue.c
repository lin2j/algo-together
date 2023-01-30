//
// Created by Kenny on 2022/8/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "priority_queue.h"

/*
 * 优先队列的自动扩容，大约为原来容量的2倍
 *
 * Parameters:
 * - queue 队列
 * - min_size 最小容量
 */
void grow(PriorityQueue queue, int min_size) {
        int new_size = min_size << 1;
        int *new_data = (int *) malloc(new_size * sizeof(int));
        memset(new_data, 0, sizeof(int) * new_size);
        memcpy(new_data, queue->data, sizeof(int) * queue->capacity);

        free(queue->data);
        queue->data = new_data;
        queue->capacity = new_size;
}

PriorityQueue new_priority_queue(int capacity) {
        if (capacity < 0) {
                printf("capacity of priority queue must not be negative.");
                exit(EXIT_FAILURE);
        }
        PriorityQueue queue = (PriorityQueue) malloc(sizeof(PriorityQueue));
        queue->capacity = capacity;
        queue->size = 0;
        queue->data = (int *) malloc(sizeof(int) * capacity);

        return queue;
}

void pq_free(PriorityQueue queue) {
        free(queue->data);
        free(queue);
}

void pq_offer(PriorityQueue queue, int e) {
        if (queue->size >= queue->capacity)
                grow(queue, queue->size + 1);

        int k = queue->size;
        while (k > 0) {
                int parent = k >> 1;
                if (queue->data[parent] <= e) {
                        break;
                }
                queue->data[k] = queue->data[parent];
                k = parent;
        }
        queue->data[k] = e;
        queue->size++;
}

bool pq_poll(PriorityQueue queue, int *e) {
        if (queue->size == 0)
                return false;

        *e = queue->data[0];
        int x = queue->data[queue->size - 1];
        int k = 0;
        int half = queue->size >> 1;
        while (k < half) {
                int child = 2 * k + 1;
                if (child + 1 < queue->size
                    && queue->data[child] > queue->data[child + 1])
                        child++;
                if (queue->data[child] >= x)
                        break;
                queue->data[k] = queue->data[child];
                k = child;
        }
        queue->data[k] = x;
        queue->size--;

        return true;
}

bool pq_peek(PriorityQueue queue, int *e) {
        if (queue->size == 0)
                return false;
        *e = queue->data[0];


        return true;
}

void pq_print(PriorityQueue queue)
{
        printf("size is %d, capacity is %d. ", queue->size, queue->capacity);
        for(int i = 0; i < queue->size; i++) {
                if (i == 0)
                        printf("[");
                printf("%d", queue->data[i]);
                if (i == queue->size - 1) {
                        printf("]\n");
                } else {
                        printf(", ");
                }
        }
}
