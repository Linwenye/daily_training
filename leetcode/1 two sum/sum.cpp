#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;




class Solution {
public:
	struct pair {
		int index;
		int num;
		pair(int i, int n) {
			index = i;
			num = n;
		}
		bool operator < (const pair &other) const { return num < other.num; }
	};

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> my_map;
		for (int i = 0; i < nums.size(); i++)
		{
			my_map[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (my_map.count(target - nums[i]) > 0 && my_map[target - nums[i]] != i) {
				res.push_back(i);
				res.push_back(my_map[target - nums[i]]);
				break;
			}
		}
		return res;
	}

};

int main() {
	int a[4] = { 3,2,4 };
	vector<int> test(a, a + 3);
	Solution so;
	so.twoSum(test, 6);
	return 0;
}