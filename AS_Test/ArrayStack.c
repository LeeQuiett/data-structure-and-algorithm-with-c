#include "ArrayStack.h"

void AS_CreatStack(ArrayStack** Stack, int Capacity) 
{
	// ������ ���� ����ҿ� ����
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	// �Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	// Capacity �� Top �ʱ�ȭ
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}


void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, int Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

int AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

int AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack)
{
	return ((Stack->Capacity - 1) == (Stack->Top));
}