//
// Created by Jay on 2022/7/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t{
    int 		val;
    struct Node_t 	*next;
    struct Node_t 	*prev;
} Node;

/*
 *
 */
typedef struct {
    Node	*head;
    Node 	*tail;
    int	        size;
} LinkedList;

static Node * new_node(int e)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = e;

	return node;
}

static LinkedList * new_linked_list()
{
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

static void linked_list_add_last(LinkedList *list, Node *node)
{
	list->size += 1;

	if (list->head == NULL) {
		/* first node */
		list->head = list->tail = node;
		list->head->next = list->tail;
		list->tail->prev = list->head;

		return;
	}

	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
	list->head->prev = node;
	node->next = list->head;
}

static Node * linked_list_peek_last(LinkedList *list)
{
	return list->tail;
}

static void linked_list_free(LinkedList *list)
{
	if (list == NULL)
		return;

	int next_size = 0;
	Node *p = list->head;
	while(next_size < list->size) {
		Node *next = p->next;
		free(p);
		p = next;
		next_size++;
	}
	free(list);
	list = NULL;
}

static bool linked_list_poll_last(LinkedList *list, Node **node)
{
	if (list->size == 0)
		return false;

	Node *tail = list->tail;
	if (list->size == 1) {
		list->head = NULL;
		list->tail = NULL;
	} else {
		tail->prev->next = list->head;
		list->head->prev = tail->prev;
		list->tail = tail->prev;
	}
	list->size -= 1;

	*node = tail;

	return true;
}


static void print_list(LinkedList *list)
{
	if (list == NULL)
		return;

	int next_size = 0;
	Node *p = list->head;
	while(next_size < list->size) {
		next_size++;
		printf("(%d:%d:%d)", p->prev->val, p->val, p->next->val);
		p = p->next;
	}
	printf("\n");

}

// ====================
typedef struct {
    LinkedList *push_stack;
    LinkedList *pop_stack;
} CQueue;


CQueue* cQueueCreate() {
	CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
	queue->push_stack = new_linked_list();
	queue->pop_stack = new_linked_list();

	return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
	Node *node = new_node(value);
	linked_list_add_last(obj->push_stack, node);
}

int cQueueDeleteHead(CQueue* obj) {
	Node *node;
	if(obj->pop_stack->size == 0)
		while(linked_list_poll_last(obj->push_stack, &node))
			linked_list_add_last(obj->pop_stack, node);
	bool result = linked_list_poll_last(obj->pop_stack, &node);
	return result ? node->val : -1;
}

void cQueueFree(CQueue* obj) {
	linked_list_free(obj->push_stack);
	linked_list_free(obj->pop_stack);
	free(obj);
}
//=================

int main(int argc, char **argv)
{
//	LinkedList *list = new_linked_list();
//
//	printf("add last: 1\n");
//	linked_list_add_last(list, 1);
//	printf("add last: 2\n");
//	linked_list_add_last(list, 2);
//	printf("add last: 3\n");
//	linked_list_add_last(list, 3);
//	printf("add last: 4\n");
//	linked_list_add_last(list, 4);
//	print_list(list);
//
//	printf("peek last: ");
//	Node *node = linked_list_peek_last(list);
//	printf("(%d:%d:%d)\n", node->prev->val, node->val, node->next->val);
//
//	int e;
//	linked_list_poll_last(list, &e);
//	printf("poll last: %d\n", e);
//	linked_list_poll_last(list, &e);
//	printf("poll last: %d\n", e);
//	linked_list_poll_last(list, &e);
//	printf("poll last: %d\n", e);
////	linked_list_poll_last(list, &e);
////	printf("poll last: %d\n", e);
//	print_list(list);

	int e;
	CQueue *queue = cQueueCreate();
	printf("1\n");
	cQueueDeleteHead(queue);
	printf("2\n");
	cQueueAppendTail(queue, 12);
	printf("3\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("4\n");
	cQueueAppendTail(queue, 10);
	printf("5\n");
	cQueueAppendTail(queue, 9);
	printf("6\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("7\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("8\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("9\n");
	cQueueAppendTail(queue, 20);
	printf("10\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("11\n");
	cQueueAppendTail(queue, 1);
	printf("12\n");
	cQueueAppendTail(queue, 8);
	printf("13\n");
	cQueueAppendTail(queue, 20);
	printf("14\n");
	cQueueAppendTail(queue, 1);
	printf("15\n");
	cQueueAppendTail(queue, 11);
	printf("16\n");
	cQueueAppendTail(queue, 2);
	printf("17\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("18\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("19\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
	printf("20\n");
	e = cQueueDeleteHead(queue);
	printf("delete: %d\n", e);
}