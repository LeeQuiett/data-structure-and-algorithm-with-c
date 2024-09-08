#include <stdio.h>
#include <stdlib.h>

// 노드 구조체에 탐색 횟수를 추가
typedef struct tagNode {
	int data;
	int searchCount;  // 탐색 횟수
	struct tagNode* nextNode;
} Node;

// 새로운 노드를 생성하는 함수
Node* createNode(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->searchCount = 0;  // 탐색 횟수 초기화
	newNode->nextNode = NULL;
	return newNode;
}

// 리스트를 탐색하고, 노드의 탐색 횟수를 증가시키며 리스트를 정렬하는 함수
Node* searchAndRearrange(Node** head, int target) {
	Node* current = (*head);
	Node* prev = NULL;
	Node* match = NULL;

	// 노드를 탐색
	while (current != NULL) {
		if (current->data == target) {
			match = current;
			current->searchCount++;  // 탐색 횟수 증가
			break;
		}
		prev = current;
		current = current->nextNode;
	}

	// 노드를 찾았고, 그 노드를 앞으로 옮길 필요가 있는 경우
	if (match != NULL && prev != NULL) {
		// 탐색 횟수가 더 높은 노드가 있으면 앞쪽으로 이동
		Node* tmp = (*head);
		Node* tmpPrev = NULL;

		// 리스트를 순회하여 탐색 횟수가 더 낮은 위치로 이동
		while (tmp != match && tmp->searchCount >= match->searchCount) {
			tmpPrev = tmp;
			tmp = tmp->nextNode;
		}

		// 노드를 해당 위치로 옮김
		if (tmp != match) {
			// 현재 노드를 리스트에서 제거
			prev->nextNode = match->nextNode;

			// match 노드를 새로운 위치로 삽입
			if (tmpPrev != NULL) {
				tmpPrev->nextNode = match;
			}
			else {
				// match가 가장 앞쪽으로 이동해야 할 경우
				(*head) = match;
			}
			match->nextNode = tmp;
		}
	}

	return match;
}