#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		else
		{
			string s = to_string(x);
			int start = 0;
			int end = s.size()-1;
			while (start < end) {
				if (s[start++] != s[end--]) {
					return false;
				}

			}
			return true;
		}
	}
};

int main() {
	Solution so;
	so.isPalindrome(121);
}