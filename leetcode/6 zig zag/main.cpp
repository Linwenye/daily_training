#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string res = "";
		if (numRows == 1)
		{
			return s;
		}
		for (unsigned i = 0; i < numRows; i++)
		{
			for (unsigned j = i; j < s.length();)
			{
				res += s[j];
				if (i != 0 && i != numRows - 1)
				{
					int next_index = j + 2 * (numRows - i - 1);
					if (next_index < s.length())
					{
						res += s[next_index];
					}
				}
				// attention! need to check input 1 here! Otherwise dead loop
				j += 2 * (numRows - 1);
			}
		}
		return res;
	}
};


int main() {
	string s("PAYPALISHIRING");
	Solution so = Solution();
	string res = so.convert(s, 3);
	cout << res;
	cout << endl;
	cout << so.convert(s, 4);
	cout << so.convert("A", 1);
}