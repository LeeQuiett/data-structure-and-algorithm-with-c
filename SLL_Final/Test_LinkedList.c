#include "LinkedList.h"

int main(vold) {
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreatNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreatNode(-1);
	SLL_InsertNewHead(&List, NewNode);

	NewNode = SLL_CreatNode(-2);
	SLL_InsertNewHead(&List, NewNode);

	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n",i, Current->Data);
	}
	//SLL_DestroyList(&List);

	// ����Ʈ�� �� ��° ��� �ڿ� �� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreatNode(3000);

	SLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	Count = SLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// ��� ��带 �޸𸮿��� ����
	SLL_DestroyList(&List);

	return 0;
}