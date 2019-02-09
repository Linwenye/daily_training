#include <vector>
using namespace std;

class Solution {
public:
	int target;
	int n;
	int search(vector<int>& nums, int target) {
		this->target = target;
		this->n = nums.size();
		int mid = (nums.size() - 1) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			return bsearch(nums, mid + 1, mid - 1, false, true);
		}
		else {
			return bsearch(nums, mid + 1, mid - 1, true,false);
		}
	}

	int bsearch(vector<int>& nums, int l, int r, bool less_than_r,bool biger_than_l) {
		if (l == r) {
			return nums[l] == target ? l : -1;
		}

		int mid = cal_mid(l, r);
		if (nums[mid] == target) {
			return mid;
		}
		else {
			if (less_than_r&&biger_than_l) {
				if (nums[mid] < target) {
					return bsearch(nums, mid + 1, r, true, true);
				}
				else {
					return bsearch(nums, l, mid - 1, true, true);
				}
			}
			else if (less_than_r) {
				if (nums[mid] > nums[r]) {
					return bsearch(nums, mid + 1, r, true, false);
				}
				else {
					return bsearch(nums, l, mid - 1, true, true);
				}
			}
			else {  //biger than l
				if (nums[mid] < nums[l]) {
					return bsearch(nums, l, mid - 1, false, true);
				}
				else {
					return bsearch(nums, mid + 1, r, true, true);
				}
			}
		}

	}

	int cal_mid(int l, int r) {
		if (l < r) {
			return (l + r) / 2;
		}
		else {
			int mid = (l + r + n) / 2;
			return mid < n ? mid : mid - n;
		}
	}
};
