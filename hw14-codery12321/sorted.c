#include <stdlib.h>
#include <stdio.h>
#include "sorted.h"

TreeNode * buildTreeNode(bool isleaf, int chr, long count)
{
  TreeNode * newTreeNode = malloc(sizeof(TreeNode));
  newTreeNode -> isleaf = isleaf;
  newTreeNode -> chr = chr;
  newTreeNode -> count = count;
  newTreeNode -> left = NULL;
  newTreeNode -> right = NULL;
  return newTreeNode;
}

ListNode * buildListNode (TreeNode * tree)
{
  ListNode * newListNode = malloc(sizeof(ListNode));
  newListNode -> tree = tree;
  newListNode -> next = NULL;

  return newListNode;
}

bool firstGreater(TreeNode * ptr1, TreeNode * ptr2)
{
  if(ptr1 -> count > ptr2 -> count)
  {
    return true;
  }
  if (ptr1 -> count == ptr2 -> count && ptr2 -> isleaf && ptr1 -> chr > ptr2 -> chr)
  {
    return true;
  }
  if (ptr1 -> count == ptr2 -> count && !ptr1 -> isleaf)
  {
    return true;
  }
  return false;
}

ListNode * insert(ListNode * head, ListNode * newNode)
{
  if(head == NULL)
  {
    head = newNode;
    return head;
  }

  if(head -> next == NULL)
  {
    if(firstGreater(head -> tree, newNode -> tree))
    {
      newNode -> next = head;
      head = newNode;
    }
    else
    {
      head -> next = newNode;
    }
    return head;
  }
  ListNode * temp = head;
  ListNode * p = head -> next;

  if (!newNode -> tree -> isleaf)
  {
    while(p != NULL)
    {
      if(newNode -> tree -> count < p -> tree -> count)
      {
        newNode -> next = p;
        temp -> next = newNode;
        return head;
      }
      temp = temp -> next;
      p = p -> next;
    }
    temp -> next = newNode;
    return head;
  }
  if(firstGreater(head -> tree, newNode -> tree))
  {
    newNode -> next = head;
    head = newNode;
    return head;
  }
  while(p != NULL)
  {
    if(firstGreater(newNode -> tree, temp -> tree) && firstGreater(p -> tree, newNode -> tree))
    {
      newNode -> next = p;
      temp -> next = newNode;
      return head;

    }
    temp = temp -> next;
    p = p->next;

  }
  temp -> next = newNode;
  return head;
}
ListNode * createASCIIList(long * asciiCount)
{
  int chr = 0;
  ListNode * head = NULL;
  ListNode * temp = NULL;
  while (chr < ASCII_SIZE)
  {
    if(asciiCount[chr] > 0)
    {
      temp = buildListNode(buildTreeNode(true, chr, asciiCount[chr]));
      head = insert(head, temp);
    }
    chr++;
  }
  free(asciiCount);
  return head;
}
void printListNode(char * filename , ListNode * head)
{
  FILE * outFile = fopen(filename, "w");
  if(outFile == NULL)
  {
    fprintf(stderr, "\nsorted file could not be open");
    return;
  }
  ListNode * temp = head;
  while (temp != NULL)
  {
    fprintf(outFile, "%c:%ld\n", temp -> tree -> chr, temp -> tree -> count);
    temp = temp -> next;
  }
  fclose(outFile);
}

void destroyTree(TreeNode * root)
{
  if(root == NULL)
  {
    return;
  }
  destroyTree(root -> left);
  destroyTree(root -> right);
  free(root);
}
void destroyList(ListNode * head)
{
  ListNode * temp = NULL;
  while(head != NULL)
  {
    temp = head;
    head = head -> next;
    destroyTree(temp -> tree);
    free(temp);
  }
}
