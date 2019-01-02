#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		p = p + "##"; //pivot
		s = s + "##"; //pivot  Genius!
		bool **res_metrix = new bool*[p.size()];
		for (int i = 0; i < p.size(); i++) {
			res_metrix[i] = new bool[s.size()]();
		}
		res_metrix[p.size()-1][s.size()-1] = true;

		for (int i = p.size() - 2; i >= 0; i--)
		{
			for (int j = s.size() - 2; j >= 0; j--)
			{
				bool first_match = s[j] == p[i] || p[i] == '.';
				if (p[i + 1] == '*')
				{
					res_metrix[i][j] = res_metrix[i][j + 1] && first_match || res_metrix[i + 2][j];
				}
				else {
					res_metrix[i][j] = res_metrix[i + 1][j + 1] && first_match;

				}
			}
		}
		cout << res_metrix[0][0];
		return res_metrix[0][0];
	}
};

int main() {
	Solution so;
	so.isMatch("aab", "c*a*b");
	so.isMatch("aab", "a*");
	so.isMatch("aa", "a*");
	so.isMatch("aa", "a");
	so.isMatch("mississippi", "mis*is*p*.");
}