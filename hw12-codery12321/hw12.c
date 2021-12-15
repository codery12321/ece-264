#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <stdbool.h>

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");
		return EXIT_FAILURE;
	}

	float result; //store the result of your calculation here.
	int status = 1;

	FILE * fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		fprintf(stdout, "error opening file\n");
		return EXIT_FAILURE;
	}

	result = solver(fp, &status);

	if(!status)
	{
		fclose(fp);
		fprintf(stdout, "number of operators is wrong\n");
		return EXIT_FAILURE;
	}

	fprintf(stdout, "%f\n", result);
	fclose(fp);
	return EXIT_SUCCESS;

	/* Insert code here to perform the RPN calculation.
	Don't forget to free any memory you allocate once you're done with it! */


}
