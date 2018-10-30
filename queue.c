#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	void *next;
};

struct Queue
{
	void *start;
	void *end;
	int size;
};

void enqueue(void *queue, int value);
void *dequeue(void *queue);
int is_empty(void *queue);

int main(int argc, char **argv)
{
	struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->size = 0;
	enqueue(queue, 10);
	enqueue(queue, 10);
	enqueue(queue, 10);
	/* code */
	/* TODO: DEQUEUE AND FREE */
	return 0;
}

void enqueue(void *queue, int value)
{
	struct Queue *new_queue = (struct Queue*) queue;
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->value = value;
	if (is_empty(queue) == 0) {
		new_queue->start = (void *) new_node;
		new_queue->end = (void *) new_node;
		new_queue->size = new_queue->size + 1;
		return;
	}
	struct Node *temp = (struct Node*) new_queue->end;
	temp->next = new_node;
	new_queue->end = new_node;
}

void *dequeue(void *queue)
{
	struct Queue *new_queue = (struct Queue*) queue;
	struct Node *temp = (struct Node*) new_queue->start;
	new_queue->start = temp->next;
	new_queue->size = new_queue->size - 1;
	return temp;
}

int is_empty(void *queue)
{
	struct Queue *new_queue = (struct Queue*) queue;
	return new_queue->size;
}