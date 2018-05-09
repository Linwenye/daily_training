#include <iostream>
#include <climits>
using namespace std;

//������ж��������10����β������ /10����ԭ������ͬ�������
class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		bool is_neg = x < 0;
		unsigned int t = is_neg ? -x : x;
		while (t != 0)
		{
			res = 10 * res + t % 10;
			if (res > INT_MAX)
			{
				return 0;
			}
			t /= 10;
		}

		return int(is_neg ? -res : res);
	}
};

int main() {
	Solution so = Solution();
	cout << so.reverse(1534236469);
	cout << so.reverse(INT_MAX);
	cout << so.reverse(INT_MIN);
	cout << so.reverse(-10);
}