#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

void freePaths(PathLL * p) {
	//fill in
	while (p -> head -> next != NULL)
	{
		PathNode * q = p -> head -> next;
		freeNode(p -> head);
		p -> head = q;
	}
	freeNode(p -> head);
	free(p);
}

PathNode * buildNode(char * path) {
	//fill in

	PathNode * newNode = malloc(sizeof(PathNode *));
	newNode -> path = malloc(strlen(path + 1) * sizeof(char));
	strcpy(newNode -> path, path);
	newNode -> next = NULL;
	return newNode;
	//WARNING: don't forget to use strcpy to copy path into the
	//new node. Don't just set them equal, otherwise if the input path changes
	//the node will have the wrong path.
}

void freeNode(PathNode * p) {
	//fill in
	free(p -> path);
	free(p);
}
int numTurns (char * path)
{
	int count = 0;
	int i = 0;
	while (path[i + 1] != '\0')
	{
		if (path[i] != path[i + 1])
		{
			count++;
		}
		i++;
	}
	return count;
}
bool order(PathNode * p, PathNode * n)
{
	if(strlen(p -> path) > strlen(n -> path))
	{
		return true;
	}
	if(numTurns(p -> path) > numTurns(n -> path) && strlen(p -> path) == strlen(n -> path))
	{
		return true;
	}
	if(strcmp(p -> path, n -> path) > 0 && numTurns(p -> path) == numTurns(n -> path) && strlen(p -> path) == strlen(n -> path))
	{
		return true;
	}
	return false;
}
bool addNode(PathLL * paths, char * path) {

	//fill in
	PathNode * p = paths -> head;
	PathNode * n = buildNode(path);
	if(p == NULL)
	{
		paths -> head = n;
		return true;
	}
	if (order(p,n))
	{
		n -> next = p;
		paths -> head = n;
		return true;
	}
	while(p -> next != NULL)
	{
		if(!order(p,n) && order(p -> next, n))
		{
			n -> next = p -> next;
			p -> next = n;
			return true;
		}
		p = p -> next;
	}
	p -> next = n;
	return true;
}

bool removeNode(PathLL * paths, char * path) {
  //fill in
	PathNode * p = paths -> head;
	PathNode * q;

	if(paths -> head == NULL)
	{
		return false;
	}

	if(strcmp(paths -> head -> path, path) == 0)
	{
		paths -> head = paths -> head -> next;
		free(p);
		return true;
	}
	while( p -> next != NULL)
	{
		if(strcmp(p -> next -> path, path) == 0)
		{
			q = p -> next;
			p -> next = q -> next;
			free(q);
			return true;
		}
		p = p -> next;
	}
	return false;
}

bool containsNode(PathLL * paths, char * path) {
	//fill in
	PathNode * p = paths -> head;
	if (paths -> head == NULL)
	{
		return false;
	}
	while (p != NULL)
	{
		if (strcmp(p -> path, path) == 0)
		{
			return true;
		}
		p = p -> next;
	}
	return false;
}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}
