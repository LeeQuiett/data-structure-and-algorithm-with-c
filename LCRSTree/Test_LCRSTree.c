#include "LCRSTree.h"

int main(void)
{
	// 노드 생성
	LCRSNode* Root = LCRS_CreatNode('A');
	LCRSNode* B = LCRS_CreatNode('B');
	LCRSNode* C = LCRS_CreatNode('C');
	LCRSNode* D = LCRS_CreatNode('D');
	LCRSNode* E = LCRS_CreatNode('E');
	LCRSNode* F = LCRS_CreatNode('F');
	LCRSNode* G = LCRS_CreatNode('G');
	LCRSNode* H = LCRS_CreatNode('H');
	LCRSNode* I = LCRS_CreatNode('I');
	LCRSNode* J = LCRS_CreatNode('J');
	LCRSNode* K = LCRS_CreatNode('K');

	// 트리에 노드 추가
	LCRS_AddChildNode(Root, B);
	LCRS_AddChildNode(B, C);
	LCRS_AddChildNode(B, D);
	LCRS_AddChildNode(D, E);
	LCRS_AddChildNode(D, F);

	LCRS_AddChildNode(Root, G);
	LCRS_AddChildNode(G, H);

	LCRS_AddChildNode(Root, I);
	LCRS_AddChildNode(I, J);
	LCRS_AddChildNode(J, K);

	// 트리 출력
	LCRS_PrintTree(Root, 0);

	LCRS_DestroyTree(Root);

	return 0;
}