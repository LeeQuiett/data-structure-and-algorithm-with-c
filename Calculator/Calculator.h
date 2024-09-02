#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum
{
	LEFT_PARNTESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIED = '/',
	SPACE = ' ', OPERAND
} SYMBOL;

int IsNumber(char Cipher); // Cipher ��ȣ
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char Operator1, char Operator2); // Prior ������
void GetPostfix(char* InfixExpression, char* PostfixExpression); // Postfix ���̻�, InfixExpression ���� ǥ��, PostfixExpression ���� ǥ��
double Calculate(char* PostfixExpression);

#endif