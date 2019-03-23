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
	/*
		all numbers to be positive
	*/
	vector<int>* candidates;
	vector<vector<int>> res;

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = &candidates;

	}

	void candidate_sum(int i_of_candidates, vector<int> &temp_res,int target) {
		if (target == 0) {
			
		}
	}
};

int main() {

}
