#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;




class Solution {
public:
	struct pair {
		int index;
		int num;
		pair(int i, int n) {
			index = i;
			num = n;
		}
		bool operator < (const pair &other) const { return num < other.num; }
	};

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size()<3)
		{
			return res;
		}
		map<int, int> my_map;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			my_map[nums[i]] = i;
		}

		int pre_i = nums[0] - 1;
		int pre_j = nums[1] - 1;

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (nums[i]==pre_i)
			{
				continue;
			}
			else
			{
				pre_i = nums[i];
			}
			for (int j = i + 1; j < nums.size() - 1; j++) {
				if (nums[j] == pre_j)
				{
					continue;
				}
				else
				{
					pre_j = nums[j];
				}
				int expected = -nums[i] - nums[j];
				if (my_map.count(expected) > 0 && my_map[expected]>j) {
					vector<int> temp_res;
					temp_res.push_back(nums[i]);
					temp_res.push_back(nums[j]);
					temp_res.push_back(expected);
					res.push_back(temp_res);
				}
			}
		}

		return res;
	}

};

int main() {
	int a[6] = { -1, 0, 1, 2, -1, -4 };
	vector<int> test(a, a + 6);
	Solution so;
	so.threeSum(test);
	return 0;
}