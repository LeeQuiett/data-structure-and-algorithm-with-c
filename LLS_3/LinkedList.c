#include <stdio.h>
#include <stdlib.h>

typedef enum {
    NODE_TYPE_INT,
    NODE_TYPE_INT2
} NodeType;

typedef struct Node {
    NodeType type;    // ����� Ÿ���� �ĺ�
    void* data;       // ����� ������ (�پ��� Ÿ�� ����)
    struct Node* next; // ���� ��带 ����Ű�� ������
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} Index;

// ��� ����
Node* creatNode(NodeType type, void* data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->type = type;
        newNode->data = data;
        newNode->next = NULL;
    }
}