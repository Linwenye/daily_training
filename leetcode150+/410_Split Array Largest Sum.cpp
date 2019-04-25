class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		int **dp = new int *[n];
		for (int i = 0; i < n; ++i)
		{
			dp[i] = new int[m]();
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < m; ++j)  // j==k represent spliting into k pieces
			{
				for (int k = i; k < n - j; ++k)
				{
					
				}
			}
		}
	}

};