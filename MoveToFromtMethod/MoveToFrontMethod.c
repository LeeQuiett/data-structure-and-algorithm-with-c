#include <stdio.h>
//���� �̵� ���� Ž��
typedef struct Node {
	int data;
	struct Node* nextNode;
} Node;

Node* moveToFront(Node** head, int target)
{
	Node* current = (*head);
	Node* prev = NULL;
	Node* match = NULL;

	while (current != NULL)
	{
		if (current->data == target)
		{	
			match = current;

			if (prev != NULL)
			{
			prev->nextNode = current->nextNode;
			current->nextNode = (*head);
			(*head) = current;
			}
			break;
		}
		else
		{
			prev = current;
			current = current->nextNode;
		}
	}

	return match;
}