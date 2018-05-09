#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		unsigned i = 0;
		int res = 0;
		bool nega = false;
		while (str[i] == ' ')
		{
			i++;
		}
		if (i >= str.length())
		{
			return 0;
		}
		else if (str[i] == '-')
		{
			nega = true;
			i++;
		}
		else if (str[i] == '+') {
			nega = false;
			i++;
		}
		else if (str[i]<'0' || str[i]>'9')
		{
			return 0;
		}
		int tmp;
		while (i < str.length())
		{
			if (str[i]<'0' || str[i]>'9')
			{
				break;
			}
			tmp = res;
			res = 10 * res + (str[i] - '0');
			if (tmp != res / 10) //Òç³ö
			{
				if (nega)
				{
					return INT_MIN;
				}
				else
				{
					return INT_MAX;
				}
			}
			i++;
		}
		return nega ? -res : res;
	}


};

int main() {
	Solution so = Solution();
	cout << so.myAtoi("42") << endl;
	cout << so.myAtoi("   -42") << endl;
	cout << so.myAtoi("4193 with words") << endl;
	cout << so.myAtoi("words and 987") << endl;
	cout << so.myAtoi("-91283472332");
}