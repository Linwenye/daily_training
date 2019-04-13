#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int destination_i = nums.size() - 1;

		while (destination_i > 0) {
			int j;
			for (j = destination_i - 1; j >= 0; j--)
			{
				if (nums[j]>=destination_i-j)
				{
					destination_i = j;
					break;
				}
			}
			if (j<0)
			{
				return false;
			}
		}
		return true;
	}
};