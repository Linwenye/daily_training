#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		char num_hash[9];
		// check row
		for (int i = 0; i < 9; i++) {
			memset(num_hash, 0, sizeof(num_hash));
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					if (num_hash[board[i][j] - '1'] != 0) {
						return false;
					}
					else {
						num_hash[board[i][j] - '1'] = 1;
					}
				}
			}
		}
		// check column
		for (int i = 0; i < 9; i++) {
			memset(num_hash, 0, sizeof(num_hash));
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					if (num_hash[board[j][i] - '1'] != 0) {
						return false;
					}
					else {
						num_hash[board[j][i] - '1'] = 1;
					}
				}
			}
		}
		// check box
		for (int i = 0; i < 9; i = i + 3) {
			for (int j = 0; j < 9; j = j + 3) {
				memset(num_hash, 0, sizeof(num_hash));
				for (int k = i; k < 3 + i; k++) {
					for (int p = j; p < 3 + j; p++) {
						if (board[k][p] != '.') {
							if (num_hash[board[k][p] - '1'] != 0) {
								return false;
							}
							else {
								num_hash[board[k][p] - '1'] = 1;
							}
						}
					}
				}
			}
		}
		return true;

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
	cout << s.isValidSudoku(board) << endl;
	system("pause");
}
