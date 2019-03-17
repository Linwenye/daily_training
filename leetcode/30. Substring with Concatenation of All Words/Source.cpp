#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/*
		判断不必要的判断，移除~
	*/
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (words.empty()) return res;

		unordered_map<string, int> words_map;
		int word_size = words[0].length();
		for (const auto &word : words) {
			words_map[word] = words_map[word] + 1;
		}

		for (int i = 0; i < word_size; i++) {
			for (int j = i; j < s.length(); j += word_size) {

			}
		}
	}
};

int main() {
	
}