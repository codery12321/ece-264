#ifndef SORTED_H
#define SORTED_H
#define ASCII_SIZE 256
#include <stdbool.h>

/* An example of a TreeNode and ListNode structure. You don't have to use exactly this */
typedef struct TreeNode {
  bool isleaf;
  int chr;
  long count;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
   TreeNode *tree;
   struct ListNode *next;
} ListNode;

TreeNode * buildTreeNode(bool isleaf, int chr, long count);
ListNode * buildListNode (TreeNode * tree);
bool firstGreater(TreeNode * ptr1, TreeNode * ptr2);
ListNode * insert(ListNode * head, ListNode * newNode);
ListNode * createASCIIList(long * asciiCount);
void printListNode(char * filename , ListNode * head);
void destroyTree(TreeNode * root);
void destroyList(ListNode * head);
#endif
