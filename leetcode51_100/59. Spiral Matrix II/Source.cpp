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
	vector<vector<int>> generateMatrix(int n) {
		int **matrix = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[n]();
		}

		int print_length = (n + 1) / 2;
		int count = 1;
		for (int t = 0; t < print_length; t++) // ´òÓ¡µÚi²ã
		{
			for (int j = t; j < n - t; j++) matrix[t][j] = count++;
			for (int i = t + 1; i < n - t; i++) matrix[i][n - t - 1] = count++;
			if (t != n - 1 - t && t != n - 1 - t)	// necessary judge
			{
				for (int j = n - t - 2; j >= t; j--) matrix[n - t - 1][j] = count++;
				for (int i = n - t - 2; i >= t + 1; i--) matrix[i][t] = count++;
			}
		}

		vector<vector<int>> res;
		for (int i = 0; i < n; i++) {
			res.push_back(vector<int>(matrix[i], matrix[i] + n));
		}
		
		return res;
	}
};