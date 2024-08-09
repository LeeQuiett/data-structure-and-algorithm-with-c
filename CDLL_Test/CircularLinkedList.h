#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int Data;
	struct Node* PrevNode;
	struct Node* NextNode;
} Node;

void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
//void CDLL_DestroyNode(Node* Node);
void CDLL_DestroyList(Node* Head);
Node* CDLL_CreatNode(int NewData);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);