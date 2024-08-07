#include "DoublyLinkedList.h"

// ��� ����
Node* DLL_CreatNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = NewData;
	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

// ����Ʈ �Ҹ�
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

// ��� �߰�
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

// ��� ����
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

// ��� ����
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

// ��� Ž��
Node* DLL_GetNodeCount(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && Location > 0) 
	{
		Current = Current->NextNode;
		Location--;
	}
	return Current;
}

// ��� ���� ����
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