#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int n_queen(int n);
int main() {
	int num = -1;
	while (true)
	{
		scanf("%d", &num);
		if (num==0)
		{
			break;
		}
		printf("%d\n", n_queen(num));
	}
}

int n_queen(int n)
{
	int res = 0;
	vector<pair<int, int>> points;
	
	return res;
}
