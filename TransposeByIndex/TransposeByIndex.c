#include <stdio.h>

typedef struct tagNode
{
	int data;
	struct tagNode* nextNode;
} Node;

// ������� ����� transpose �Լ�
Node* transposeByIndex(Node** head, int target)
{
	Node* current = (*head);
	Node* match = NULL;
	int currentIndex = 0;
	int prevIndex = -1;

	// Ÿ�� ��带 ã�� ������ ����Ʈ�� ��ȸ
	while (current != NULL)
	{
		if (current->data == target)
		{
			match = current;
			break;
		}
		current = current->nextNode;
		currentIndex++;
	}

	// Ÿ�� ��带 ã�Ұ�, �װ��� ù ��° ��尡 �ƴ� ���
	if (match != NULL && currentIndex > 0); 
	{
		// �ε����� ������� ���� ��带 ã��
		Node* prev = (*head);
		for (int i = 0; i < currentIndex - 1; i++)
		{
			prev = prev->nextNode;
		}

		// Ÿ�� ��带 ���� ���� ��ȯ
		if (currentIndex == 1)
		{
			// Ÿ���� �� ��° ����� ���, head�� Ÿ������ ����
			(*head) = match;
		}
		else
		{
			// ���� ����� ���� ��带 ã��
			Node* pprev = (*head);
			for (int i = 0; i < currentIndex - 2; i++)
			{
				pprev = pprev->nextNode;
			}
			pprev->nextNode = match;
		}
		
		// ���� ���� Ÿ�� ����� ������ ����
		prev->nextNode = match->nextNode;
		match->nextNode = prev;
	}
	return match;
}