#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nums;
	int target;
	vector<int> searchRange(vector<int>& nums, int target) {
		this->nums = nums;
		this->target = target;
		return b_search(0, nums.size() - 1);
	}

	vector<int> b_search(int l, int r) {
		vector<int> res;
		int mid;
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
				res.push_back(search_r(mid+1, r));
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
		int mid;
		while (true) {
			if (l >= r) return l - 1;
			mid = (l + r) / 2;
			if (nums[mid] == target) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
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