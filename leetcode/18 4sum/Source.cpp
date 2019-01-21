#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void threeSum(vector<int>& nums, int index, int target, int to_add, vector<vector<int>> &res) {
		int distance = 2147483647; //max
		for (int i = index; i < nums.size() - 2; i++) {
			int expected = target - nums[i];
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				int temp_dis = nums[l] + nums[r] - expected;
				if (temp_dis == 0) {
					vector<int> temp;
					temp.push_back(to_add);
					temp.push_back(nums[i]);
					temp.push_back(nums[l]);
					temp.push_back(nums[r]);
					res.push_back(temp);

					// TODO: add different          
					int l_value = nums[l];
					int r_value = nums[r];
					while (nums[l] == l_value) {
						l++;
					}
					while (nums[r] == r_value)
					{
						r--;
					}
				}
				else if (temp_dis < 0)
				{
					int l_value = nums[l];
					while (nums[l] == l_value) {
						l++;
					}
				}
				else
				{
					int r_value = nums[r];
					while (nums[r] == r_value)
					{
						r--;
					}
				}
			}
		}
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;

		// TODO: skip repeat
		int pre = nums[0] + 1;
		for (int i = 0; i < nums.size() - 3; i++) {
			if (nums[i] == pre) {
				continue;
			}
			pre = nums[i];
			threeSum(nums, i + 1, target - nums[i], nums[i], res);
		}

		return res;
	}
};

int main() {
	Solution so;
	int a[6] = { 1, 0, -1, 0, -2, 2 };
	vector<int> nums(a, a + 6);

	so.fourSum(nums, 0);
	return 0;
}