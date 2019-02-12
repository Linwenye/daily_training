//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	int target;
//	int n;
//	int search(vector<int>& nums, int target) {
//		if (nums.empty()) return -1;
//		this->target = target;
//		this->n = nums.size();
//		int mid = (nums.size() - 1) / 2;
//		if (nums[mid] == target) {
//			return mid;
//		}
//		else if (nums[mid] < target) {
//			return bsearch(nums, mid_plus(mid), mid_minus(mid), false, true);
//		}
//		else {
//			return bsearch(nums, mid_plus(mid), mid_minus(mid), true, false);
//		}
//	}
//
//	int mid_plus(int mid) {
//		return mid + 1 >= n ? 0 : mid + 1;
//	}
//	int mid_minus(int mid) {
//		return mid - 1 >= 0 ? mid - 1 : n - 1;
//	}
//	int bsearch(vector<int>& nums, int l, int r) {
//		
//
//	}
//
//	int cal_mid(int l, int r) {
//		if (l < r) {
//			return (l + r) / 2;
//		}
//		else {
//			int mid = (l + r + n) / 2;
//			return mid < n ? mid : mid - n;
//		}
//	}
//};
//
////int main() {
////	Solution so;
////	//int a[7] = { 4, 5, 6, 7, 0, 1, 2 };
////	int a[9] = { 9,1,2,3,4,5,6,7,8 };
////	vector<int> b(a, a + 9);
////	cout << so.search(b, 9);
////	system("pause");
////}
