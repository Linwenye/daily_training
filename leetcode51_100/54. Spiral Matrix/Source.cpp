#include <vector>
#include <algorithm>
using namespace std;

/*
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty() || matrix[0].empty())
		{
			return res;
		}
		int m = matrix[0].size();
		int n = matrix.size();
		int print_length = (min(m, n) + 1) / 2;
		for (int t = 0; t < print_length; t++) // ´òÓ¡µÚi²ã
		{
			for (int j = t; j < m - t; j++) res.push_back(matrix[t][j]);
			for (int i = t + 1; i < n - t; i++) res.push_back(matrix[i][m - t - 1]);
			if (t != m - 1 - t && t != n - 1 - t)
			{
				for (int j = m - t - 2; j >= t; j--) res.push_back(matrix[n - t - 1][j]);
				for (int i = n - t - 2; i >= t + 1; i--) res.push_back(matrix[i][t]);
			}
		}

		return res;
	}
};