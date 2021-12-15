#ifndef _CALC_H_
#define _CALC_H_

#include <stdbool.h>
typedef struct Node {
    float val;
    struct Node * next;
} Node;

char * getstr(FILE * fp);
bool checkfile(char * string);
float solver(FILE * fp, int * stat);
Node * eval(Node * head, char * read);
float calc(char * string);
Node * build(float value);
Node * push(Node * head, float value);
Node * pop(Node * head, float * value);

#endif
