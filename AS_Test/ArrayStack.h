#pragma once
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int Data;
} Node;

typedef struct ArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void AS_CreatStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, int Data);
int AS_Pop(ArrayStack* Stack);
int AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);
int AS_IsFull(ArrayStack* Stack);