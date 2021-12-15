#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"


#ifndef BUILDTREE_OFF
/*bool parser(Scanner * s)
{
	Token token = nextToken(s);
	if(token.type == T_VAL) return true;

	if(token.type == T_LPAREN)
	{
		if(!parser(s))
		{
			return false;
		}
		token = nextToken(s);
		if(!(token.type == T_ADD) || !(token.type == T_SUB) || !(token.type == T_DIV) || !(token.type == T_MUL))
		{
			return false;
		}
		if(!parser(s))
		{
			return false;
		}
		token = nextToken(s);
		if(token.type == T_RPAREN)
		{
			return true;
		}
		return true;
	}
}*/

TreeNode * buildExpressionTree(Scanner * s) {

//FILL IN
	Token token = nextToken(s);
	TreeNode * newNode;

	if(token.type == T_VAL)
	{
		newNode = buildTreeNode(token);
		return newNode;
	}

	if(token.type == T_LPAREN)
	{
		TreeNode * left_child = buildExpressionTree(s);
		token = nextToken(s);
		if((token.type == T_ADD) || (token.type == T_SUB) || (token.type == T_DIV) || (token.type == T_MUL))
		{
			newNode = buildTreeNode(token);
		}
		TreeNode * right_child = buildExpressionTree(s);
		newNode -> left = left_child;
		newNode -> right = right_child;
		token = nextToken(s);
		if(token.type == T_RPAREN)
		{
			return newNode;
		}
	}
	return newNode;
}
#endif

#ifndef POSTFIX_OFF
void printNode(Token t, FILE * fptr)
{
	switch(t.type)
	{
		case T_ADD: fprintf(fptr, "+ "); break;
		case T_VAL: fprintf(fptr, "%f ", t.value); break;
		case T_MUL: fprintf(fptr, "* "); break;
		case T_DIV: fprintf(fptr, "/ "); break;
		case T_SUB: fprintf(fptr, "- "); break;
		case T_EOF: fprintf(fptr, "\n "); break;
		default: break;
	}

}
void makePostFix(TreeNode * t, FILE * fptr) {

//FILL IN
if(t == NULL)
{
	return;
}
makePostFix(t -> left, fptr);
makePostFix(t -> right, fptr);
printNode(t -> t, fptr);
}
#endif
