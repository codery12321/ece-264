#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calc.h"

char * getstr(FILE * fp)
{
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char * string = malloc(length * sizeof(char *));
	fgets(string, length + 1, fp);
	return string;
}

bool checkfile(char * string)
{
  int str_ind = 0;
  int i = 0;
  char * read = malloc((strlen(string) + 1) * sizeof(char));
  int op_count = 0;
  int num_count = 0;
  while (string[str_ind] != '\0')
  {
    if(string[str_ind] == ' ')
    {
      read[i] = '\0';
      if (atof(read) == 0)
      {
        op_count++;
      }
      else
      {
        num_count++;
      }
      i = 0;
      str_ind++;
      strncpy(read, "\0\0\0\0\0\0\0\0\0", strlen(read));
    }
    else
    {
      read[i] = string[str_ind];
      i++;
      str_ind++;
    }
  }
  read[i] = '\0';
  if (atof(read) == 0)
  {
    op_count++;
  }
  else
  {
    num_count++;
  }
  free(read);
  if((op_count + 1) == num_count)
  {
    return true;
  }
  return false;
}

float solver(FILE * fp, int * status)
{
  char * string = getstr(fp);
  float result = 1;
  if(!checkfile(string))
  {
    *status = 0;
    return result;
  }
  result = calc(string);

  free(string);
  return result;
}

/*  Insert a value at the beginning of a list
    list: a pointer to the list
    val: the new value to insert
    return: a pointer to the list that has val in it

    Before:
            ┌-----┬------┐   ┌-----┬------┐
    list--->|  x  |   ---|-->|  y  |   ---|--┐
            └-----┴------┘   └-----┴------┘  ┴
    After:
            ┌-----┬------┐   ┌-----┬------┐   ┌-----┬------┐
     ret--->| val |   ---|-->|  x  |   ---|-->|  y  |   ---|--┐
            └-----┴------┘   └-----┴------┘   └-----┴------┘  ┴
*/
Node * eval(Node * head, char * read)
{
  float val1;
  float val2;
  float ans;
  head = pop(head, &val1);
  head = pop(head, &val2);

  switch(read[0])
  {
    case '+':
      ans = val1 + val2;
      break;
    case '-':
      ans = val2 - val1;
      break;
    case '/':
      ans = val2 / val1;
      break;
    case '*':
      ans = val1 * val2;
      break;
  }
  head = push(head, ans);
  return head;
}

float calc(char * string)
{
  float result;
  int i = 0;
  int str_ind = 0;
  char * read = malloc((strlen(string) + 1) * sizeof(char));
  Node * head = NULL;
  while (string[str_ind] != '\0')
  {
    if(string[str_ind] == ' ')
    {
      read[i] = '\0';
      if(atof(read) == 0)
      {
        head = eval(head, read);
      }
      else
      {
        head = push(head, (float) atof(read));
      }
      i = 0;
      str_ind++;
      strncpy(read, "\0\0\0\0\0\0\0", strlen(read));
    }
    else
    {
      read[i] = string[str_ind];
      i++;
      str_ind++;
    }
  }
  read[i] = '\0';
  head = eval(head, read);
  free(read);
  head = pop(head, &result);
  return result;
}
Node * build(float value)
{
  Node * newNode = malloc(sizeof(Node *));
  newNode -> val = value;
  newNode -> next = NULL;
  return newNode;
}

Node * push(Node * head, float value)
{
  if (head == NULL)
  {
    head = build(value);
    return head;
  }
  Node * newNode  = build(value);
  newNode -> next = head;
  head = newNode;
  return head;
}

Node * pop(Node * head, float * value)
{
  if(head == NULL)
  {
    return head;
  }
  * value = head -> val;
  Node * temp = head;
  head = head -> next;
  free(temp);
  return head;
}
