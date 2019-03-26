#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> str_map;
		vector<string> strs_copy = strs;
		for (int i = 0; i < strs.size(); i++) {
			sort(strs_copy[i].begin(), strs_copy[i].end());
			str_map[strs_copy[i]].push_back(strs[i]);
		}
		for (auto &str_value:str_map)
		{
			res.push_back(str_value.second);
		}
		return res;
	}
};

int main() {
	vector<string> a = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution so;
	so.groupAnagrams(a);
}