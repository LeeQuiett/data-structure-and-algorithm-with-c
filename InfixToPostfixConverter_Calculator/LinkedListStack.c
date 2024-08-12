#include "LinkedListStack.h"

void LLS_CreatStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

Node* LLS_CreatNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = (char*)malloc(sizeof(strlen(NewData) + 1));

	strcpy(NewNode->data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* Node)
{
	free(Node->data);
	free(Node);
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* CurrentTopNode = Stack->List;
		while (CurrentTopNode != NULL && CurrentTopNode->NextNode != Stack->Top)
		{
			CurrentTopNode = CurrentTopNode->NextNode;
		}
		Stack->Top = CurrentTopNode;
		Stack->Top->NextNode = NULL;
	}

	return TopNode;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack)) 
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	free(Stack);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}

	Stack->Top = NewNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return (Stack->Top);
}

int LLS_GetSize(LinkedListStack* Stack)
{
	Node* CurrentNode = Stack->List;
	int Cnt = 0;

	while (CurrentNode != NULL)
	{
		CurrentNode = CurrentNode->NextNode;
		Cnt++;
	}
	
	return Cnt;
}