//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		vector<vector<int>> res;
//		vector<int> temp_res;
//		if (nums.empty())
//		{
//			return res;
//		}
//		sort(nums.begin(), nums.end());
//		my_permute(nums, res, temp_res, 0);
//		unordered_map<string, int> examine;
//
//		for (auto& nums_list : res)
//		{
//			string num_str = "";
//			for (auto& num : nums_list)
//				num_str.push_back(num + '0');
//
//			examine[num_str]++;
//			cout << num_str.c_str << endl;
//		}
//		for (auto& t : examine) {
//			if (t.second > 1)
//			{
//				cout << "repeated: " << t.first.c_str();
//				cout << endl;
//			}
//		}
//		return res;
//
//	}
//private:
//	void my_permute(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp_res, int i) {
//		if (i == nums.size()) {
//			res.push_back(temp_res);
//			return;
//		}
//		temp_res.push_back(nums[i]);
//		my_permute(nums, res, temp_res, i + 1);
//		temp_res.pop_back();
//
//		for (int j = i + 1; j < nums.size(); j++) {
//			if (nums[j] != nums[i] && nums[j - 1] != nums[j]) {
//				swap(nums[i], nums[j]);
//				temp_res.push_back(nums[i]);
//				my_permute(nums, res, temp_res, i + 1);
//				temp_res.pop_back();
//				swap(nums[i], nums[j]);
//			}
//		}
//	}
//};
//
//int main() {
//	//vector<int> a = { 2,3,3,4,1 };
//	vector<int> a = { 1,2,1,2,3,3,04 };
//	Solution so;
//	so.permuteUnique(a);
//	system("pause");
//}