#include <iostream>
#include <vector>

using namespace std;
 
/* 八皇后问题解决 */

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {

	}
};

int main() {
	vector<vector<char> > board(9);
	string strs[9] = { ".87654321","2........","3........","4........","5........","6........","7........","8........","9........" };
	for (int i = 0; i < 9; i++) {
		vector<char> vec(9);
		for (int j = 0; j < 9; j++) {
			char ch = strs[i][j];
			vec[j] = ch;
		}
		board[i] = vec;
	}
	Solution s;
	s.solveSudoku(board);
	system("pause");
}
