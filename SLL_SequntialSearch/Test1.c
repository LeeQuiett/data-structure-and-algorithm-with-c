#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* nextNode;
} Node;

typedef struct {
	Node* head;
	Node* tail;
} linkedList;

Node* createNode(int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->nextNode = NULL;

	return newNode;
}

linkedList* createList()
{
	linkedList* newList = (linkedList*)malloc(sizeof(linkedList));
	newList->head = NULL;
	newList->tail = NULL;

	return newList;
}

void appendList(linkedList* list, Node* newNode)
{
	if (list->head == NULL)
	{
		list->head = newNode;
		list->tail = newNode;
	}
	else
	{
		list->tail->nextNode = newNode;
		list->tail = newNode;
	}
}

void freeList(linkedList* list)
{
	Node* current = list->head;
	Node* next;

	while (current != NULL)
	{
		next = current->nextNode;
		free(current);
		current = next;
	}
	free(list);
}

Node* sequentialSearch(linkedList* list, int target, int* cnt)
{
	Node* current = list->head;
	Node* match = NULL;

	while (current != NULL)
	{
		if (current->data == target)
		{
			match = current;
			break;
		}
		else
			current = current->nextNode;
		(*cnt)++;
	}
	return match;
}


int main(void)
{
	linkedList* list = createList();

	appendList(list, createNode(20));
	appendList(list, createNode(10));
	appendList(list, createNode(30));

	// 리스트 출력
	Node* current = list->head;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->nextNode;
	}
	printf("NULL\n\n");
	
	int cnt = 1;

	printf("%d을 찾습니다... 찾은 값은: %d... %d 번째 위치에서 찾았어요!\n", 30, sequentialSearch(list, 30, &cnt)->data, cnt);

	// 메모리 해제
	freeList(list);

	return 0;
}