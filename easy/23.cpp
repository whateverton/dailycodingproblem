/*
#23 - EASY
This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

Date: 21/04/2020
Dev Time: 18h50 - 
*/
#include <stack>

typedef struct coordinates
{
	int x;
	int y;
}coord;

typedef struct node
{
	struct node *parent;
	coord current;
}node;

typedef struct my_matrix
{
	bool wall;
	bool visited;
}my_matrix;

int FastestPath(my_matrix **matrix, int M, int N, coord start, coord end)
{
	stack<node> path_stack;
	int fastest_path = 0;

	path_stack.push({ NULL,start });

	matrix[start.x][start.y].visited = true;

	while (!path_stack.empty())
	{
		/*node current_node = path_stack.pop();

		if (current_node.current == end)
			return fastest_path;
			*/
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (!matrix[i][j].visited)
				{

				}
			}
		}
	}

	return fastest_path;
}

#ifdef _23_EASY_
void CurrentSolution()
{
	std::cout << "The amount of rooms required to is: " << RoomsRequired(class_intervals, sizeof(class_intervals) / sizeof(time_interval_t)) << std::endl;
}
#endif