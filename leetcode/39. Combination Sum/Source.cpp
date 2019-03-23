#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	对比Moodle全覆盖子集问题，离散数学全覆盖问题、硬币问题、SudoKu、八皇后、算法书上的贪心算法求覆盖，跳台阶之斐波那契
	硬币问题：dp
		coin[i,j]=min{coin[i-1,j],coin[i,j-value[i]]+1}
	Moodle问题：
		i代表使用前几个学生，j代表有无课程的二进制转换成的十进制数

*/

class Solution {
public:

	vector<int>* candidates;
	vector<vector<int>> res;

	/*
	all numbers to be positive
	*/
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = &candidates;
		if (candidates.empty()) return res;
		vector<int> temp_res;
		candidate_sum(0, temp_res, target);
		return res;
	}

	void candidate_sum(int i, vector<int> &temp_res, int target) {
		if (i >= candidates->size() || target - (*candidates)[i] < 0) return;
		else if (target - (*candidates)[i] == 0) {
			temp_res.push_back((*candidates)[i]);
			res.push_back(temp_res);
			return;
		}
		else {
			vector<int> temp_res2;
			temp_res2 = temp_res;
			temp_res.push_back((*candidates)[i]);
			// use candidate[i]
			candidate_sum(i, temp_res, target - (*candidates)[i]);
			// not use
			candidate_sum(i + 1, temp_res2, target);
		}

	}
};

int main() {
	vector<int>a = { 2,3,5 };
	Solution so;
	so.combinationSum(a, 8);
	system("pause");
}
