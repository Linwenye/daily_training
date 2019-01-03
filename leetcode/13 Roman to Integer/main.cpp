#include <iostream>

using namespace std;


class Solution {

public:
	Solution() {
		for (int t = 0; t < 7; t++) {
			my_map[roman[t]] = integer[t];
		}
		my_map['#'] = 0;

	}
	int integer[7] = { 1,5,10,50,100,500,1000 };
	char roman[7] = { 'I','V','X','L','C','D','M' };
	int my_map[256];

	int romanToInt(string s) {

		s += '#';
		int res = 0;
		for (int j = 0; j < s.size()-1; j++) {
			if (my_map[s[j]]<my_map[s[j+1]])
			{
				res += my_map[s[j + 1]] - my_map[s[j]];
				j++;
			}
			else {
				res += my_map[s[j]];
			}
		}
		return res;
	}
};


int main() {
	Solution so;
	cout << so.romanToInt("MCMXCIV");
}