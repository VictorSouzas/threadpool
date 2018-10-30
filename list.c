#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	void *next;
	void *before;
};

struct List
{
	void *start;
	void *end;
	int size;
};