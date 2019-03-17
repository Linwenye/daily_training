#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> index_stack;
		int *res = new int[s.size()];
		int longest = 0;
		for (int i = 0; i < s.size(); i++) {
			res[i] = INT_MAX;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				index_stack.push_back(i);
			}
			else {
				if (!index_stack.empty()) {
					// Ô½½ç¼ì²é
					if (index_stack.back() == 0) res[i] = 0;
					else {
						res[i] = min(index_stack.back(), res[index_stack.back() - 1]);
					}
					longest = max(longest, i - res[i] + 1);
					index_stack.pop_back();
				}
			}
		}
		return longest;
	}
};


int main() {
	Solution so;
	string s1 = "()((())()(("; //6
	string s2 = "()()))()";//4
	string s3 = "))(("; //0
	cout << so.longestValidParentheses(s1) << endl;
	cout << so.longestValidParentheses(s2) << endl;
	cout << so.longestValidParentheses(s3) << endl;
	//cout << so.longestValidParentheses(s1)<<endl;
	system("pause");
}