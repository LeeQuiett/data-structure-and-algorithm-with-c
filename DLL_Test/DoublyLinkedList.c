#include "DoublyLinkedList.h"

// 노드 생성
Node* DLL_CreatNode(ElementType NewData)
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
		while (Tail->NextNode != NULL) {
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

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}