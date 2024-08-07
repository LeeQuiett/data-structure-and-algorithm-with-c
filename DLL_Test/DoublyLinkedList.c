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

	if (*Head == NULL) {
		puts("Error: Head is NULL!");
		return;
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