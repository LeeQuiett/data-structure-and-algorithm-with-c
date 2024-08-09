#include "CircularLinkedList.h"

void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	if (*Head == NULL) {
		(*Head) = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		// 테일과 헤드 사이에 NewNode를 삽입한다.
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

void CDLL_RemoveNode(Node** Head, Node* Remove) 
{
	if (Remove == NULL) {
		puts("Remove Node is NULL!");
		return;
	}

	if (*Head == Remove) {
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		(*Head) = Remove->NextNode;
		
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;		
	}
	else
	{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;

		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
	free(Remove);
}

void CDLL_DestroyList(Node* Head)
{
	Node* Current = Head;
	Node* NextNode;
	int index = 0;

	if (Head == NULL) {
		puts("List is already empty.\n");
		return;
	}

	if (Current->NextNode == Head) {
		free(Head);
		puts("List[0] Destroyed");
		return;
	}
	else {
		while (Current->NextNode != Head)
		{
			NextNode = Current->NextNode;
			free(Current);
			Current = NextNode;
			printf("List[%d] Destroyed\n", index++);
		}
		free(Current);
	}
}