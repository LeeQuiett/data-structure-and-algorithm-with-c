#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>



typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
} Node;

Node* SSL_CreatNode(int NewData);
void SSL_DestroyNode(Node* Node);
void SSL_AppendNode(Node** Head, Node* NewNode);
void SSL_InsertAfter(Node* Current, Node* NewNode);
void SSL_InsertNewHead(Node** Head, Node* Remove);
void SSL_RemoveNode(Node** Head, Node* Remove);
Node* SSL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif