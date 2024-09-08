#include <stdio.h>

typedef struct tagNode
{
	int data;
	struct tagNode* nextNode;
} Node;

// 계수법을 사용한 transpose 함수
Node* transposeByIndex(Node** head, int target)
{
	Node* current = (*head);
	Node* match = NULL;
	int currentIndex = 0;
	int prevIndex = -1;

	// 타겟 노드를 찾을 때까지 리스트를 순회
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

	// 타겟 노드를 찾았고, 그것이 첫 번째 노드가 아닌 경우
	if (match != NULL && currentIndex > 0); 
	{
		// 인덱스를 기반으로 이전 노드를 찾음
		Node* prev = (*head);
		for (int i = 0; i < currentIndex - 1; i++)
		{
			prev = prev->nextNode;
		}

		// 타겟 노드를 이전 노드와 교환
		if (currentIndex == 1)
		{
			// 타겟이 두 번째 노드일 경우, head를 타겟으로 변경
			(*head) = match;
		}
		else
		{
			// 이전 노드의 이전 노드를 찾음
			Node* pprev = (*head);
			for (int i = 0; i < currentIndex - 2; i++)
			{
				pprev = pprev->nextNode;
			}
			pprev->nextNode = match;
		}
		
		// 이전 노드와 타겟 노드의 연결을 변경
		prev->nextNode = match->nextNode;
		match->nextNode = prev;
	}
	return match;
}