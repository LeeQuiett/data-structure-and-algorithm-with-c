#include "LinkedListStack.h"

int main(void)
{
	int count = 0;

	Node* Popped;
	LinkedListStack* Stack;

	LLS_CreatStack(&Stack);

	LLS_Push(Stack, LLS_CreatNode("abc"));
	LLS_Push(Stack, LLS_CreatNode("def"));
	LLS_Push(Stack, LLS_CreatNode("efg"));
	LLS_Push(Stack, LLS_CreatNode("hij"));

	count = LLS_GetSize(Stack);
	printf("Size: %d Top: %s\n\n", count, LLS_Top(Stack)->data);

	for (int i = 0; i < count; i++)
	{
		if (LLS_IsEmpty(Stack)) 
		{
			break;
		}

		Popped = LLS_Pop(Stack);
		printf("Popped: %s ", Popped->data);

		LLS_DestroyNode(Popped);

		if (!LLS_IsEmpty(Stack)) 
		{
			printf("Current Top: %s\n", LLS_Top(Stack)->data);
		}
		else 
		{
			puts("Stakc Is Empty.");
		}
	}

	LLS_DestroyStack(Stack);

	return 0;
}