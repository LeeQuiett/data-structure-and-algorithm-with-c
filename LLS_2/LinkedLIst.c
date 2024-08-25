#include "LinkedList.h"

// ��� ����
Node* SSL_CreatNode(int NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void SSL_DestroyNode(Node* Node)
{
	free(Node);
}

// ��� �߰�
void SSL_AppendNode(Node** Head, Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = *Head;
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// ��� ����
void SSL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SSL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		*Head = NewHead;
	}
	else
	{
		NewHead->NextNode = *Head;
		(*Head) = NewHead;
	}
}

void SSL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

// ��� Ž��
Node* SSL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && Location > 0)
	{
		Location--;
		Current = Current->NextNode;
	}

	return Current;
}

// ��� ���� ����

int SSL_GetNodeCount(Node* Head)
{
	Node* Current = Head;
	int cnt = 0;
	while (Current != NULL)
	{
		Current = Current->NextNode;
		cnt++;
	}
	return cnt;
}