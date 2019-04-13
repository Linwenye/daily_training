#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int left = -1;
		map <char, int> exist;
		for (unsigned i = 0; i < s.length(); i++)
		{
			if (exist.count(s[i]))
			{
				int pre_index = exist[s[i]];
				left = max(left, pre_index);
			}
			exist[s[i]] = i;  // 每次更新，则保证index是最后面出现的该字符的索引，因而才用比较left和pre_index

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