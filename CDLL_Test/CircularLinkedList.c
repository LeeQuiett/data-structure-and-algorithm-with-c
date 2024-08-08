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