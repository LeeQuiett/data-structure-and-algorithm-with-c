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

int IsNumber(char Cipher); // Cipher 암호
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char Operator1, char Operator2); // Prior 이전의
void GetPostfix(char* InfixExpression, char* PostfixExpression); // Postfix 접미사, InfixExpression 중위 표현, PostfixExpression 후위 표현
double Calculate(char* PostfixExpression);

#endif