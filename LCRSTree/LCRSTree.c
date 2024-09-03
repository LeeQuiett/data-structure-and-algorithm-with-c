#include "LCRSTree.h"

LCRSNode* LCRS_CreatNode(char NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}


void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);

	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* Child)
{
	if (ParentNode->LeftChild == NULL)
	{
		ParentNode->LeftChild = Child;
	}
	else
	{
		LCRSNode* TempNode = ParentNode->LeftChild;
		while (TempNode->RightSibling != NULL)
		{
			TempNode = TempNode->RightSibling;
		}
		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	// 들여쓰기
	for (int i = 0; i < Depth - 1; i++)
	{
		printf("   ");
	}

	if (Depth > 0) // 자식 노드 여부 표시
		printf("+--");

	// 노드 데이터 출력
	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}