#include <stdio.h>
#include <stdlib.h>

// ��� ����ü�� Ž�� Ƚ���� �߰�
typedef struct tagNode {
	int data;
	int searchCount;  // Ž�� Ƚ��
	struct tagNode* nextNode;
} Node;

// ���ο� ��带 �����ϴ� �Լ�
Node* createNode(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->searchCount = 0;  // Ž�� Ƚ�� �ʱ�ȭ
	newNode->nextNode = NULL;
	return newNode;
}

// ����Ʈ�� Ž���ϰ�, ����� Ž�� Ƚ���� ������Ű�� ����Ʈ�� �����ϴ� �Լ�
Node* searchAndRearrange(Node** head, int target) {
	Node* current = (*head);
	Node* prev = NULL;
	Node* match = NULL;

	// ��带 Ž��
	while (current != NULL) {
		if (current->data == target) {
			match = current;
			current->searchCount++;  // Ž�� Ƚ�� ����
			break;
		}
		prev = current;
		current = current->nextNode;
	}

	// ��带 ã�Ұ�, �� ��带 ������ �ű� �ʿ䰡 �ִ� ���
	if (match != NULL && prev != NULL) {
		// Ž�� Ƚ���� �� ���� ��尡 ������ �������� �̵�
		Node* tmp = (*head);
		Node* tmpPrev = NULL;

		// ����Ʈ�� ��ȸ�Ͽ� Ž�� Ƚ���� �� ���� ��ġ�� �̵�
		while (tmp != match && tmp->searchCount >= match->searchCount) {
			tmpPrev = tmp;
			tmp = tmp->nextNode;
		}

		// ��带 �ش� ��ġ�� �ű�
		if (tmp != match) {
			// ���� ��带 ����Ʈ���� ����
			prev->nextNode = match->nextNode;

			// match ��带 ���ο� ��ġ�� ����
			if (tmpPrev != NULL) {
				tmpPrev->nextNode = match;
			}
			else {
				// match�� ���� �������� �̵��ؾ� �� ���
				(*head) = match;
			}
			match->nextNode = tmp;
		}
	}

	return match;
}