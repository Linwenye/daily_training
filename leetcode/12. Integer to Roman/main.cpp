#include <iostream>
#include <string>

using namespace std;

int integer[7] = { 1,5,10,50,100,500,1000 };
char roman[7] = { 'I','V','X','L','C','D','M' };

class Solution {
public:
	string intToRoman(int num) {
		string res = "";

		// normally from left to right decreasing
		int quotient;
		for (int i = 6; i >= 0; i--)
		{
			quotient = num / integer[i];
			num = num%integer[i];
			if (i%2==0)
			{
				if (quotient != 4) {
					for (int j = 0; j < quotient; j++)
					{
						res += roman[i];
					}
				}

				else {
					// specially using subtraction

					res += roman[i];
					res += roman[i + 1];
				}
			}

			else {
				if (quotient==1&&num/integer[i-1]==4)
				{
					res += roman[i - 1];
					res += roman[i + 1];
					num -= 4 * integer[i - 1];
				}
				else
				{
					if (quotient) res += roman[i];
				}
			}
			
		}

		return res;
	}
};


int main() {
	Solution so;
	cout << so.intToRoman(58)<<endl;
	cout << so.intToRoman(3)<<endl;
	cout << so.intToRoman(4)<<endl;
	cout << so.intToRoman(9)<<endl;
	cout << so.intToRoman(1994)<<endl;
}