class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
		{
			return false;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();

		int left = 0;
		int right = rows * cols;
		int mid = right / 2;
		while (left < right) {
			if (matrix[mid/cols][mid%cols])
			{
				
			}
			else
			{

			}
		}
	}
};