#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "sorted.h"

int treeSize(TreeNode * root);
void printHelper(FILE * huffmanfile, FILE * headerfile, char * huffman, TreeNode * root, int level, unsigned char * whichbit, unsigned char * curbyte);
void printHuffmanHeader(char * huffmanfile, char * headerfile, TreeNode *root);
ListNode * makeHuffmanTree(ListNode * head);
TreeNode * combineTrees(TreeNode * tr1, TreeNode * tr2);


#endif
