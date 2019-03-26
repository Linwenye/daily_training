#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp_res;
		if (nums.empty())
		{
			return res;
		}
		my_permute(nums, res, temp_res, 0);
		return res;
	}
private:
	void my_permute(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp_res, int i) {
		if (i == nums.size()) {
			res.push_back(temp_res);
			return;
		}
		temp_res.push_back(nums[i]);
		my_permute(nums, res, temp_res, i + 1);
		temp_res.pop_back();

		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] != nums[j]) {
				swap(nums[i], nums[j]);
				temp_res.push_back(nums[i]);
				my_permute(nums, res, temp_res, i + 1);
				temp_res.pop_back();
				swap(nums[i], nums[j]);
			}
		}
	}
};

int main() {
	vector<int> a = { 1,2,1,2 };
	Solution so;
	so.permuteUnique(a);
	system("pause");
}