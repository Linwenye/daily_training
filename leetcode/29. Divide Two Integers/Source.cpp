#include <iostream>
using namespace std;
class Solution {
public:

	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		if (divisor == 1) return dividend;
		bool negative = (dividend < 0) ^ (divisor < 0);
		unsigned int u_dividend = dividend < 0 ? unsigned(~dividend) + 1 : dividend;
		unsigned int u_divisor = divisor < 0 ? unsigned(~divisor) + 1 : divisor;
		int res = 0;

		while (u_dividend >= u_divisor) {
			unsigned int sub = u_divisor;
			unsigned int res_adder = 1;
			while (u_dividend >= sub) {
				sub = sub << 1;
				res_adder = res_adder << 1;
			}
			u_dividend = u_dividend - (sub >> 1);  //Âß¼­ÓÒÒÆ
			res += int(res_adder >> 1);
		}

		return negative ? -res : res;
	}
};

int main() {
	Solution so;
	int a = INT_MIN;
	cout << so.divide(a, 2) << endl;
	system("pause");
}