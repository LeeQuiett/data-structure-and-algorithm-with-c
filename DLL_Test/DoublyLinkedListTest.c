#include "DoublyLinkedList.h"

int main(void) {
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;
	int count = 0;

	// ��� 5�� �߰�
	for (int i = 0; i < 5; i++)
	{
		Node* NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// ����Ʈ ���
	count = DLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->data);
		Current = Current->NextNode;
	}

	// ����Ʈ�� �� ��° ĭ �ڿ� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// ����Ʈ ���
	count = DLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->data);
		Current = Current->NextNode;
	}

	// Q: ���� ��ũ�� ����Ʈ�� �������� ����ϴ� �Լ�
	PrintReverse(List);

	// ��� ��带 �޸𸮿��� ����
	DLL_DestroyList(&List);
	printf("\nDestroying List..Done!\n");

	return 0;
}