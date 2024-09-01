#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
} Node;

typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void AS_CreatStack(ArrayStack** Stack, int Capacity)
{
	// ������ ���� ����ҿ� ����
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// �Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	// Capacity �� Top �ʱ�ȭ
	(*Stack)->Capacity - Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
	// ��带 ���� ����ҿ��� ����
	free(Stack->Nodes);

	// ������ ���� ����ҿ��� ����
	free(Stack);
}

void AS_Push(ArrayStack* Stack, int data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].data = data;
}

int AS_Pop(ArrayStack* Stack)
{
	int position = Stack->Top--;
	return Stack->Nodes[position].data;
}

int AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;

}

int AS_IsEmpty(ArrayStack* Stack)
{
	return(Stack->Top == -1);
}