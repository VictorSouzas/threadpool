#include <stdio.h>

struct node
{
	void *value;
	void *next;
};

struct queue
{
	void *start;
	void *end;
};

void enqueue(void *queue, void *node);
void * dequeue(void *queue);
int is_empty(void *queue);

int main(int argc, char **argv)
{
	printf("%s\n", argv[1]);

	FILE *input = fopen(argv[1], "r");


	/* code */
	return 0;
}

void enqueue(void *queue, void *value)
{
	struct queue *new_queue = queue;
	struct node *new_node;
	new_node->value = (void *)value;
	if (is_empty(queue)) {
		new_queue->start = (void *) new_node;
		new_queue->end = (void *) new_node;
		return;
	}
	struct node *temp = new_queue->end;
	temp->next = (void *) new_node;
	new_queue->end = (void *) new_node;
}

void * dequeue(void *queue)
{
	struct queue *new_queue = queue;
	struct node *temp = new_queue->start;
	new_queue->start = temp->next;
	return temp;
}