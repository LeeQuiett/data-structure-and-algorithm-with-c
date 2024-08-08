#include "DoublyLinkedList.h"

int main(void) {
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;
	int count = 0;

	// 노드 5개 추가
	for (int i = 0; i < 5; i++)
	{
		Node* NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	// 리스트 출력
	count = DLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->data);
		Current = Current->NextNode;
	}

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	Current = DLL_GetNodeAt(List, 2);
	NewNode = DLL_CreateNode(3000);
	DLL_InsertAfter(Current, NewNode);

	// 리스트 출력
	count = DLL_GetNodeCount(List);
	Current = List;

	for (int i = 0; i < count; i++)
	{
		printf("List[%d] : %d\n", i, Current->data);
		Current = Current->NextNode;
	}

	// Q: 더블 링크드 리스트를 역순으로 출력하는 함수
	PrintReverse(List);

	// 모든 노드를 메모리에서 제거
	DLL_DestroyList(&List);
	printf("\nDestroying List..Done!\n");

	return 0;
}