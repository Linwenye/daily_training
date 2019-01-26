#include <vector>
using namespace std;

class Solution {
public:
	
	vector<string> generateParenthesis(int n) {

		vector<string> res;
		vector<int> right_needed;
		vector<int> left_used;
		res.push_back("");
		right_needed.push_back(0);
		left_used.push_back(0);
		for (int i = 0; i < 2 * n; i++) {
			int res_size = res.size();
			for (int j = 0; j < res_size; j++) {

				if (left_used[j] == n) {
					res[j].push_back(')');
					right_needed[j]--;
				}
				else
				{

					if (right_needed[j] > 0) {
						res.push_back(res[j] + ')');
						left_used.push_back(left_used[j]);
						right_needed.push_back(right_needed[j] - 1);
					}
					res[j].push_back('(');
					right_needed[j]++;
					left_used[j]++;
				}
			}
		}

		return res;
	}
};

int main() {
	Solution so;
	so.generateParenthesis(3);
	return 0;
}