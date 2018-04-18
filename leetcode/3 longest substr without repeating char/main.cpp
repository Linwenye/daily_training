#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
	void reduce_map(map<char, int> & res_map, int t) {
		for (auto it = res_map.cbegin();it!=res_map.cend();)
		{
			if (it->second < t)
			{
				res_map.erase(it++);
			}
			else {
				++it;
			}
		}
	}
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int tmp_lenth = 0;
		map <char, int> exist;
		for (unsigned i = 0; i < s.length(); i++)
		{
			if (exist.count(s[i]))
			{	
				int pre_index = exist[s[i]];
				tmp_lenth = i - exist[s[i]];
				reduce_map(exist, pre_index);
				exist[s[i]] = i;
			}
			else
			{
				exist[s[i]] = i;
				tmp_lenth++;
			}

			if (tmp_lenth > res)
			{
				res = tmp_lenth;
			}
		}
		return res;
	}
};

//int main() {
//	Solution so = Solution();
//	string a = "bbbbb";
//	string b = "abcabcbb";
//	cout << so.lengthOfLongestSubstring(a);
//	cout << so.lengthOfLongestSubstring(b);
//	cout << so.lengthOfLongestSubstring("pwwkew");
//	system("pause");
//}