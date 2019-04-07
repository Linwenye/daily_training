#include <vector>
using namespace std;

/*
	优化：两边同时往中间，判断哪边大，小的指针往大的靠
*/
class Solution {
public:
	int trap(vector<int>& height) {
		int res = 0;
		int i = 0;
		int j = 1;
		int temp_res = 0;

		while (j < height.size())
		{

			for (j = i + 1; j < height.size(); j++)
			{
				if (height[j] >= height[i])
				{
					i = j;
					res += temp_res;
					temp_res = 0;
					break;
				}
				else
				{
					temp_res += height[i] - height[j];
				}
			}
		}
		temp_res = 0;
		int r = height.size() - 1;
		int cursor = r - 1;
		while (cursor >= i) // height[i] represent the maximum
		{
			for (cursor = r - 1; cursor >= i; cursor--)
			{
				if (height[cursor] >= height[r]) {
					res += temp_res;
					temp_res = 0;
					r = cursor;
					break;
				}
				else {
					temp_res += height[r] - height[cursor];
				}
			}
		}
		return res;
	}
};

int main() {
	vector<int> a = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution so;
	so.trap(a);
	system("pause");
}