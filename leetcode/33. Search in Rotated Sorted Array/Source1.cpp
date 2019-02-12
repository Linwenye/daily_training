#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int target;
	int n;
	int search(vector<int>& nums, int target) {
		this->target = target;
		this->n = nums.size();
		if (nums.empty()) {
			return -1;
		}
		return bsearch(nums, 0, nums.size() - 1);
	}

	int bsearch(vector<int>& nums, int l, int r) {

		if (l == r) {
			if (nums[l] == target) return l;
			else return -1;
		}
		else {

			int mid = (l + r) / 2;
			if (nums[l] <= nums[mid]) {
				if (nums[l] <= target && target <= nums[mid]) {
					return bsearch(nums, l, mid);
				}
				else {
					return bsearch(nums, mid + 1, r);
				}
			}
			else { //nums[mid]<nums[l]  -> 断层在l 和mid之间
				if (nums[mid] < target && target <= nums[r]) {
					return bsearch(nums, mid + 1, r);
				}
				else {
					return bsearch(nums, l, mid);
				}
			}
		}
	}
};

int main() {
	Solution so;
	int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
	//int a[9] = { 9,1,2,3,4,5,6,7,8 };
	vector<int> b(a, a + 7);
	cout << so.search(b, 3);
	system("pause");
}
