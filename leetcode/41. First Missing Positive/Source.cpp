#include <vector>
using namespace std;
/*
	����[1,1]������������ѭ��
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) {
				i++;
			}
			else
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] != j + 1)
			{
				return j + 1;
			}
		}
		return nums.size() + 1;
	}
};