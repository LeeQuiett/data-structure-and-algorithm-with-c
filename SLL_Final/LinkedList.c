#include "LinkedList.h"

// ��� ����
Node* SLL_CreatNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� �Ҹ�
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

// ����Ʈ �Ҹ�
void SLL_DestroyList(Node** Head) {
	Node* Current = *Head;
	Node* Next = NULL;
	int count = 0;

	while (Current != NULL) {
		Next = Current->NextNode;
		SLL_DestroyNode(Current);
		Current = Next;
		printf("Deleted the %d-th node!\n", count);
		count++;
	}
}

// ��� �߰�
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
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
	}
}

// ��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if ((*Head) == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// ��� ����

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == NULL || Remove == NULL) {
		printf("Error: Head or Remove node is NULL\n");
	}

	if ((*Head) == Remove)
	{
		*Head = Remove->NextNode;
		SLL_DestroyNode(Remove);
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL) {
			Current->NextNode = Remove->NextNode;
			SLL_DestroyNode(Remove);
		}
		else
		{
			printf("Error: Node to remove not found in list\n");
		}
	}
}

// ��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && Location > 0) {
		Current = Current->NextNode;
		Location--;
	}
	return Current;
}

// ��� ���� ����
int SLL_GetNodeCount(Node* Head) {
	int count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;
}