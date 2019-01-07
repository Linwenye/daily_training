#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int distance = 2147483647; //max
		int res = target;
		for (int i = 0; i < nums.size() - 2; i++) {
			int expected = target - nums[i];
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				int temp_dis = nums[l] + nums[r] - expected;
				if (abs(temp_dis) < distance) {
					distance = abs(temp_dis);
					res = temp_dis + target;
				}
				if (temp_dis<0)
				{
					l++;
				}
				else
				{
					r--;
				}
			}
		}
		return res;
	}
};
