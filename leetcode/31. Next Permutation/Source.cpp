#include <vector>
#include <algorithm>
using namespace std;

// 可改进：直接reverse而不用sort，直接找非完全逆序而不用两层for循环
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		bool exited = false;
		for (int j = nums.size() - 2; j >= 0; j--) {
			for (int i = nums.size() - 1; i >= j+1; i--) {
				if (nums[j] < nums[i]) {
					swap(nums[i], nums[j]);
					sort(nums.begin() + j + 1, nums.end());
					exited = true;
					goto endloop;
				}
			}
		}
	endloop:
		if (!exited) {
			sort(nums.begin(), nums.end());
		}
	}
};

int main() {
	int a[7] = { 4,2,0,2,3,2,0 };
	vector<int> b(a, a + 7);
	Solution so;
	so.nextPermutation(b);
	system("pause");
}