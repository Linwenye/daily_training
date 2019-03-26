#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
	string a[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (!digits.size())
		{
			return res;
		}
		string pre = "";
		permuation(pre, digits, res);
		return res;
	}

	void permuation(string pre_s, string tail_digits, vector<string> &res) {

		if (!tail_digits.size())
		{
			res.push_back(pre_s);
			return;
		}

		int digit = tail_digits[0] - '0';
		tail_digits.erase(0,1);
		for (char c : a[digit]) {
			permuation(pre_s + c, tail_digits, res);
		}
	}


};

int main() {
	Solution so;
	cout<<so.letterCombinations("23")[0];
	return 0;
}