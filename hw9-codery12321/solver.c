#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"

char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}

	return retval;
}
/*The base case for a square is that the square represents the end of a path:
1.It has been visited already -- the path can't be extended this way, so return false
2.It is a wall -- this path fails, so return false.
3.It is out of bounds -- this path fails, so return false.
4.It is the exit -- this path succeeds, so return true and add this square as the last square in the path

1.If one of them returns true, that means the direction that call explores is on the solution path, which also means the current square is on the solution path. Add the current square to the solution path, and return true.
2.If the recursive call returns false, that means that direction doesn't work, so move on to the next recursive call.
3.If all the recursive calls return false, that means the current square can't be on the solution path, so return false.*/

//if data type is a structure data type, the "variable" is a "object", so "m" would be an object pointer of Maze and "curpose" would be an object of MazePos. "* path" would NOT be a object because it has a datatype of "char". Same goes for "step."

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

	//FILL IN
	if (!squareOK(curpos, m))
	{
		return false;
	}
	else if(atEnd(curpos, m))
	{
		*(path + step) = '\0';
		return true;
	}

	m -> maze[curpos.ypos][curpos.xpos].visited = true;

	curpos.ypos--; //North
	if (depthFirstSolve(m, curpos, path, step + 1))
	{
		*(path + step) = NORTH;
		return true;
	}
	curpos.ypos += 2; //goes SOUTH after going NORTH
	if (depthFirstSolve(m, curpos, path, step + 1))
	{
		*(path + step) = SOUTH;
		return true;
	}

	curpos.ypos--; //go back to original position
	curpos.xpos--; //WEST
	if (depthFirstSolve(m, curpos, path, step + 1))
	{
		*(path + step) = WEST;
		return true;
	}
	curpos.xpos += 2; //goes EAST after going WEST
	if (depthFirstSolve(m, curpos, path, step + 1))
	{
		*(path + step) = EAST;
		return true;
	}

	return false;
}
