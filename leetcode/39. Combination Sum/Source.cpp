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
