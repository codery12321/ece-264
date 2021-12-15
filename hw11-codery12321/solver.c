#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "mazehelper.h"
#include "path.h"
#include "list.h"

PathLL * solveMaze(Maze * m) {

	PathLL * successPaths = buildPaths();
	char * retval = malloc(((m->height * m->width) + 1) * sizeof(char));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	depthFirstSolve(m, mp, retval, 0, successPaths);

	free(retval);

	return successPaths;
}

void depthFirstSolve(Maze * m, MazePos curpos, char * path, int step, PathLL * successPaths) {

  //Fill in. (Your best bet is to modify a working implementation from PA08)
	if (!squareOK(curpos, m))
	{
		return;
	}
	else if(atEnd(curpos, m))
	{
		path[step] = '\0';
		if(addNode(successPaths, path))
		{
			return;
		}
		return;
	}

	m -> maze[curpos.ypos][curpos.xpos].visited = true;

	path[step] = NORTH;
	curpos.ypos--; //North
	depthFirstSolve(m, curpos, path, step + 1, successPaths);

	path[step] = SOUTH;
	curpos.ypos += 2; //goes SOUTH after going NORTH
	depthFirstSolve(m, curpos, path, step + 1, successPaths);

	path[step] = WEST;
	curpos.ypos--; //go back to original position
	curpos.xpos--; //WEST
	depthFirstSolve(m, curpos, path, step + 1, successPaths);

	path[step] = EAST;
	curpos.xpos += 2; //goes EAST after going WEST
	depthFirstSolve(m, curpos, path, step + 1, successPaths);

	curpos.xpos--;
	m -> maze[curpos.ypos][curpos.xpos].visited = false;

	return;
}
