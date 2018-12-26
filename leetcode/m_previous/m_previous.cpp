#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> my_split(string s);
int main() {
	int n = 0, m = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int tmp;
		vector<int> the_nums;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			the_nums.push_back(tmp);
		}
		sort(the_nums.begin(), the_nums.end());
		vector<int> res;
		for (int i = (n - m)>=0?(n-m):0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				res.push_back(the_nums[i] + the_nums[j]);
			}
		}
		sort(res.begin(), res.end());
		printf("%d", res[res.size()-1]);
		for (int i = res.size()-2; i >res.size()-m-1; i--)
		{
			printf(" %d", res[i]);
		}
		printf("\n");
	}
	return 0;
}

