#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		if (strs.empty()) return res;
		int i = 0;
		int max_i = strs[0].size();
		for (auto &s : strs)
		{
			if (s.size() < max_i)
			{
				max_i = s.size();
			}
		}

		char temp;
		bool same = true;
		for (; i < max_i; i++)
		{
			temp = strs[0][i];
			for (auto &s : strs)
			{
				if (s[i] != temp)
				{
					same = false;
					break;
				}
			}
			if (same)
			{
				res += temp;
			}
			else
			{
				break;
			}

		}

		return res;
	}
};


int main() {
	Solution so;
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	cout << so.longestCommonPrefix(strs);
}