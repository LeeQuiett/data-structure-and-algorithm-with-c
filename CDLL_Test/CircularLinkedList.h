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