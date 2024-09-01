#include "LinkedListStack.h"

void LLS_CreatStack(LinkedListStack** Stack)
{
	// 스택을 힙영역에 생성
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
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

Node* LLS_CreatNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
		Stack->List = NewNode;
	else
		Stack->Top->NextNode = NewNode;

	Stack->Top = NewNode;
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
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != TopNode)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}
	return TopNode;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int cnt = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		cnt++;
	}
	return cnt;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}