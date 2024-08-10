#include "CircularLinkedList.h"

int main(void) 
{
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreatNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	count = CDLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
	}
	puts("\nInserting 3000 After [2]\n");

	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreatNode(3000);

	CDLL_InsertAfter(Current, NewNode);

	count = CDLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
	}

	printf("\nRemoving Node at 2...\n");

	Current = CDLL_GetNodeAt(List, 2);
	CDLL_RemoveNode(&List, Current);

	count = CDLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < 10; i++)
	{
		printf("List[%d] : %d\n", i, Current->Data);
		Current = Current->NextNode;
	}
}