#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> temp_res;
		back_track(candidates, target, 0, temp_res, res);
		return res;
	}

	// 与39 对比，仍需去重~
	void back_track(vector<int> &candidates, int target, int i, vector<int> &temp_res, vector<vector<int>>& res) {
		if (target == 0)
		{
			res.push_back(temp_res);
			return;
		}
		else if (i >= candidates.size()||target < candidates[i] )
		{
			return;
		}
		// choosing i
		temp_res.push_back(candidates[i]);
		back_track(candidates, target - candidates[i], i + 1, temp_res, res);
		temp_res.pop_back();

		// not choosing i
		int j;
		for (j = i + 1; j < candidates.size(); j++)
		{
			if (candidates[j] != candidates[i])
			{
				break;
			}
		}
		back_track(candidates, target, j, temp_res, res);
	}
};

int main() {
	vector<int>a = { 10,1,2,7,6,1,5 };
	vector<int> b = { 2,5,2,1,2 };
	Solution so;
	so.combinationSum2(b, 5);
	system("pause");
}