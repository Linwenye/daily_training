#include <stdio.h>
#include <vector>

using namespace std;
int **graph;
int **visited;

int rows, collums;
int get_component_size(int **graph);
void dfs(int i, int j);
bool new_adjenct(int i, int j);
int main() {

	while (true)
	{
		scanf("%d %d", &rows, &collums);
		if (rows == 0)
		{
			break;
		}

		graph = new int *[rows];
		visited = new int *[rows];
		for (int i = 0; i < rows; i++) {
			graph[i] = new int[collums]();
			visited[i] = new int[collums]();
		}

		char tmp;
		for (size_t i = 0; i < rows; i++)
		{
 			for (size_t j = 0; j < collums; j++)
			{
				do 
				{
					scanf("%c", &tmp);
				} while (tmp!='@'&&tmp!='*');

				if (tmp == '@')
				{
					graph[i][j] = 1;
				}
			}
		}
		printf("%d\n", get_component_size(graph));

		delete[] graph;
	}
	return 0;
}

int get_component_size(int ** graph)
{
	int res = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		{
			if (visited[i][j] == 0 && graph[i][j] == 1)
			{
				res++;
				dfs(i, j);
			}
		}
	}

	return res;
}

void dfs(int i, int j) {
	visited[i][j] = 1;
	for (int k = -1; k < 2; k++)
	{
		for (int p = -1; p < 2; p++)
		{
			if (!(p == 0 && k == 0) && new_adjenct(i + k, j + p))
			{
				dfs(i + k, j + p);
			}
		}
	}
}

bool new_adjenct(int i, int j) {
	if (i >= rows || j >= collums || i < 0 || j < 0)
	{
		return false;
	}
	return visited[i][j] == 0 && graph[i][j] == 1;
}