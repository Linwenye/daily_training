#include <iostream>
#include <vector>
using namespace std;
1 2 3
4 5 6
7 8 9
* 0 #

N



int jump(int num_to_jump, int n) {
	int res = 0;
	for (int i=0;i<3;i++)
	{
		res += dp[jump_rule[num_to_jump]][n-1];
	}
	dp[num_to_jump][n] = res;
	return res;

}

int main() {
	const int n = 5;
	int dp[12][n];
	int jump_rule[12][3];

	jump_rule.push_back()
	//jump(jump_num);
}