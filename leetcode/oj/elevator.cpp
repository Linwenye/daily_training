#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> my_split(string s);
int main() {
	string line;
	while (getline(cin, line))
	{
		int tmp = 0;
		int res=0;
		vector<int> the_str = my_split(line);
		if (the_str[0]==0)
		{
			break;
		}
		for (int i=1;i<the_str.size();i++)
		{
			if (the_str[i]==0)
			{
				break;
			}
			if (the_str[i]>tmp)
			{
				res += 6*(the_str[i]-tmp);
				tmp = the_str[i];
			}
			else if (the_str[i]<tmp)
			{
				res += 4 * (tmp - the_str[i]);
				tmp = the_str[i];
			}
		}
		res += 5 * (the_str.size() - 1);
		cout << res << endl;
	}
	return 0;
}

vector<int> my_split(string s) {
	vector<int> split_res;
	string tmp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			split_res.push_back(atoi(tmp.c_str()));
			tmp = "";
		}
		else {
			tmp += s[i];
			if (i == s.size() - 1)
			{
				split_res.push_back(atoi(tmp.c_str()));
			}
		}
	}
	return split_res;
}