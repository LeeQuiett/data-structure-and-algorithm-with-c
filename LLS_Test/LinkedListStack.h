#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char* data;
	struct Node* NextNode;
} Node;

typedef struct LinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void LLS_CreatStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreatNode(char* data);
void LLS_DestroyNode(Node* Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);