#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nums; // 此会发生复制一遍！效率低
	int target;
	vector<int> searchRange(vector<int>& nums, int target) {
		this->nums = nums;
		this->target = target;
		return b_search(0, nums.size() - 1);
	}

	vector<int> b_search(int l, int r) {
		vector<int> res;
		int mid;

		/*
			待改进：l<r的条件放在while判断里，否则每次多判断一次，另一方面参考邓书，可修改只有两个条件分支而不是三个
		*/
		while (true) { 
			mid = (l + r) / 2;
			if (l > r) {
				res.push_back(-1);
				res.push_back(-1);
				return res;
			}
			if (nums[mid] < target) {
				l = mid + 1;
			}
			else if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				res.push_back(search_l(l, mid));
				res.push_back(search_r(mid, r));
				return res;
			}
		}
	}

	/* find the first not target from the left side */
	int search_l(int l, int r) {
		int mid;
		while (true) {
			if (l == r) return l;
			mid = (l + r) / 2;
			if (nums[mid] == target) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
	}

	int search_r(int l, int r) {
		if (nums[r] == target) return r;
		int mid;
		while (true) {
			if (l >= r) return l - 1;
			mid = (l + r) / 2;
			if (nums[mid] == target) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
	}
};

int main() {
	vector<int> a = { 1 };
	int b = 1;
	Solution so;
	so.searchRange(a, b);
}