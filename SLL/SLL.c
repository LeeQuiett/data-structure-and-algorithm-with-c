#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType data;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreatNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	NewNode->data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_AppendNode(Node** Head, Node* NewNode) {
	if ((*Head) == NULL) {
		*Head = NewNode;
	 }
	else {
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void SLL_DestroyNode(Node* Node) {
	free(Node);
}

void SLL_DestroyList(Node* Head) {
	Node* Current = Head;
	Node* Next;

	while (Current != NULL) {
		Next = Current->NextNode; // 다음 노드를 저장
		SLL_DestroyNode(Current); // 현재 노드 메모리 해제
		Current = Next; // 다음 노드로 이동
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while ( Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

int main(void) {
	Node* MyNode;

	Node* List = NULL;
	Node* NewNode = NULL;
	NewNode = SLL_CreatNode(117);
	SLL_AppendNode(&List, NewNode);
	NewNode = SLL_CreatNode(119);
	SLL_AppendNode(&List, NewNode);
	//SLL_DestroyList(List);

	MyNode = SLL_GetNodeAt(List, 1);
	printf("%d\n", MyNode->data);


	return 0;
}