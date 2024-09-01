#include <stdio.h>
#include <stdlib.h>

typedef enum {
    NODE_TYPE_INT,
    NODE_TYPE_INT2
} NodeType;

typedef struct Node {
    NodeType type;    // 노드의 타입을 식별
    void* data;       // 노드의 데이터 (다양한 타입 가능)
    struct Node* next; // 다음 노드를 가리키는 포인터
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} Index;

// 노드 생성
Node* creatNode(NodeType type, void* data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->type = type;
        newNode->data = data;
        newNode->next = NULL;
    }
}