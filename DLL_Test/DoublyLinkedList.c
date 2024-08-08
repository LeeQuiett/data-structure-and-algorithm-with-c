#include "DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

// 리스트 소멸
int DLL_DestroyList(Node** Head)
{
	int count = 0;
	Node* Current = *Head;
	Node* Next;

	if (*Head == NULL)
	{
		puts("Error: Head is NULL!");
		return 0;
	}

	while (Current != NULL)
	{
		Next = Current->NextNode;
		DLL_DestroyNode(Current);
		Current = Next;
		count++;
	}
	*Head = NULL;
	return count;
}

// 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) 
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;	
	}
}

// 노드 제거
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (Remove == NULL)
	{
		puts("Can't Start Fucntion! cuz Remove is NULL!");
		return;
	}

	if (*Head == Remove) {
		*Head = Remove->NextNode;
		if (*Head != NULL)
		{
			(*Head)->PrevNode = NULL;
		}
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		if (Remove->NextNode != NULL) 
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}
	}

	Remove->PrevNode = NULL;
	Remove->NextNode = NULL;
	DLL_DestroyNode(Remove);
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && Location > 0) 
	{
		Current = Current->NextNode;
		Location--;
	}
	return Current;
}

// 노드 개수 세기
int DLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;
	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

// 노드 출력
void PrintNode(Node* Current) 
{
	if (Current->PrevNode == NULL)
	{
		printf("Prev: NULL");
	}
	else {
		printf("Prev: %d ", Current->PrevNode->data);
	}

	printf("Current: %d ", Current->data);

	if (Current->NextNode == NULL)
	{
		printf("Next: NULL");
	}
	else
	{
		printf("Next: %d ", Current->NextNode->data);
	}	
}

// Q: 더블 링크드 리스트를 역순으로 출력하는 함수
void PrintReverse(Node* Head) {
	Node* Current = Head;
	int i = DLL_GetNodeCount(Head) - 1;

	while (Current->NextNode != NULL) {
		Current = Current->NextNode;
	}

	puts("\nPrint Reverse..!");
	while (Current->PrevNode != NULL) {
		printf("List[%d]: %d\n", i, Current->data);
		Current = Current->PrevNode;
		i--;
	}
	printf("List[%d]: %d\n", i, Current->data);
}