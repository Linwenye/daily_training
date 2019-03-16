#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int start = 0, longest = 0, left_count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left_count++;
			}
			else {
				left_count--;
			}
			//if (left_count < 0) {
			//	// invalid
			//	start = i + 1;
			//	left_count = 0;
			//}

			if (left_count == 0) {
				int temp_length = i - start + 1;
				longest = temp_length > longest ? temp_length : longest;
			}
		}
	}
};


int main() {
	Solution so;
	string s1 = "()((())()(("; //6
	string s2 = "()()))()";//4
	string s3 = "))(("; //0
	cout << so.longestValidParentheses(s1);
}