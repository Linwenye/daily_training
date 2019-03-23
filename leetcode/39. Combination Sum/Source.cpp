#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	�Ա�Moodleȫ�����Ӽ����⣬��ɢ��ѧȫ�������⡢Ӳ�����⡢SudoKu���˻ʺ��㷨���ϵ�̰���㷨�󸲸ǣ���̨��֮쳲�����
	Ӳ�����⣺dp
		coin[i,j]=min{coin[i-1,j],coin[i,j-value[i]]+1}
	Moodle���⣺
		i����ʹ��ǰ����ѧ����j�������޿γ̵Ķ�����ת���ɵ�ʮ������

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
