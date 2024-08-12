#include "LinkedListStack.h"

void LLS_CreatStack(LinkedListStack** Stack)
{
	// 스택을 자유 저장소에 생성
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}

Node* LLS_CreatNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestroyNode(Node* Node) 
{
	free(Node->data);
	free(Node);
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


Node* LLS_Pop(LinkedListStack* Stack)
{
	// 함수가 반환할 최상위 노드 저장
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		// Top 아래에 있던 노드를 새로운 CurrentTop에 저장
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		// CurrentTop을 Top에 저장
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		count++;
		Current = Current->NextNode;
	}

	return count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}