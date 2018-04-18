#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int left = 0;
		map <char, int> exist;
		for (unsigned i = 0; i < s.length(); i++)
		{
			if (exist.count(s[i]))
			{
				int pre_index = exist[s[i]];
				left = max(left, pre_index);
			}
			exist[s[i]] = i;

			res = max((int)i - left, res);
		}
		return res;
	}

};

int main() {
	Solution so = Solution();
	string a = "bbbbb";
	string b = "abcabcbb";
	cout << so.lengthOfLongestSubstring(a);
	cout << so.lengthOfLongestSubstring(b);
	cout << so.lengthOfLongestSubstring("pwwkew");
	system("pause");
}