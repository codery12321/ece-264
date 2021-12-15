#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "sorted.h"
#include "utility.h"

int treeSize(TreeNode * root)
{
  if(root -> left == NULL && root -> right == NULL) //if (root ==  isleaf)
  {
    return 1;
  }
  if(root == NULL) //not needed
  {
    return 0;
  }
  int size = treeSize(root -> left) + treeSize(root -> right);
  return size;
}

void printHelper(FILE * huffmanfile, FILE * headerfile, char * huffman, TreeNode * root, int level, unsigned char * whichbit, unsigned char * curbyte)
{
  if(root -> isleaf)
  {
    huffman[level] = '\0';
    fprintf(huffmanfile, "%c:%s\n", root -> chr, huffman);

    writeBit(headerfile, 1, whichbit, curbyte);
    writeChar(headerfile, whichbit, curbyte, root -> chr);
    return;
  }
  writeBit(headerfile, 0, whichbit, curbyte);

  huffman[level] = '0';
  printHelper(huffmanfile, headerfile, huffman, root -> left, level + 1, whichbit, curbyte);
  huffman[level] = '1';
  printHelper(huffmanfile, headerfile, huffman, root -> right, level + 1, whichbit, curbyte);
}

void printHuffmanHeader(char * huffmanfile, char * headerfile, TreeNode *root)
{
  FILE * huffFile = fopen(huffmanfile,"w");
  FILE * headFile = fopen(headerfile, "w");
  if(huffFile == NULL)
  {
    fprintf(stderr, "\nhuffman file could not be opened");
    return;
  }
  if(headFile == NULL)
  {
    fprintf(stderr, "\nheader file could not be opened");
    return;
  }
  char * huffman = malloc(treeSize(root) * sizeof(char));
  int level = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;

  printHelper(huffFile, headFile, huffman, root, level, &whichbit, &curbyte);
  writeBit(headFile, 0,  &whichbit, &curbyte);
  padZero(headFile, &whichbit, &curbyte);

  free(huffman);
  fclose(huffFile);
  fclose(headFile);
}

ListNode * makeHuffmanTree(ListNode * head)
{
  ListNode * ln1 = NULL;
  ListNode * ln2 = NULL;
  while(head -> next -> next !=  NULL)
  {
    ln1 = head;
    ln2 = head -> next;
    ListNode * newNode = buildListNode(combineTrees(ln1 -> tree, ln2 -> tree));
    head = head -> next ->  next;
    insert(head, newNode);
    free(ln1);
    free(ln2);
  }
  if(head -> next !=  NULL)
  {
    ln1 = head -> next;
    head -> tree =combineTrees(head -> tree, ln1 -> tree);
    head -> next = NULL;
    free(ln1);
  }
  return head;
}

TreeNode * combineTrees(TreeNode * tr1, TreeNode * tr2)
{
  TreeNode * trn = buildTreeNode(0, 0, tr1 -> count + tr2 -> count);
  trn -> left = tr1;
  trn -> right = tr2;
  return trn;
}
