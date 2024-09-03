#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	char Data;
} LCRSNode;

LCRSNode* LCRS_CreatNode(char NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* Child);
void LCRS_PrintTree(LCRSNode* Node, int Depth);