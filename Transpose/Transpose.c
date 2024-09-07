#include <stdio.h>

typedef struct tagNode 
{
	int data;
	struct tagNode* nextNode;
} Node;

Node* transpose(Node** head, int target)
{
	Node* current = (*head);
	Node* pprev = NULL;
	Node* prev = NULL;
	Node* match = NULL;

	while (current != NULL)
	{
		if (current->data == target)
		{
			match = current;
			if (prev != NULL)
			{
				if (pprev != NULL)
				{
					pprev->nextNode = current;
				}
				else
				{
					(*head) = current;
				}
				prev->nextNode = current->nextNode;
				current->nextNode = prev;
			}
			break;
		}
		else
		{
			if (prev != NULL)
				pprev = prev;
			prev = current;
			current = current->nextNode;
		}
	}
	return match;
}