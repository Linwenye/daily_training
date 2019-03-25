#include <iostream>
#include <vector>

using namespace std;

/* 八皇后问题解决 */

class Solution {
public:

	void solveSudoku(vector<vector<char>>& board) {

		// set row available numbers
		for (size_t i = 0; i < 9; i++) {
			for (size_t j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
					row[i][board[i][j] - '1'] = true;
			}
		}
		// set column available numbers
		for (size_t i = 0; i < 9; i++) {
			for (size_t j = 0; j < 9; j++)
			{
				if (board[j][i] != '.')
					col[i][board[j][i] - '1'] = true;
			}
		}
		// set box
		for (size_t i = 0; i < 9; i = i + 3) {
			for (size_t j = 0; j < 9; j = j + 3)
			{
				for (size_t k = i; k < 3 + i; k++)
				{
					for (size_t m = j; m < 3 + j; m++) {
						if (board[k][m] != '.')
							box[i + j / 3][board[k][m] - '1'] = true;
					}
				}
			}
		}
		back_track(board, 0, 0);

	}
private:
	bool row[9][9] = { 0 };
	bool col[9][9] = { 0 };
	bool box[9][9] = { 0 };

	bool back_track(vector<vector<char>>& board, size_t i, size_t j) {
		if (i == 9) return true;
		while (board[i][j] != '.')
		{
			if (j == 8) {
				if (i == 8) return true;
				i++;
				j = 0;
			}
			else {
				j++;
			}
		}

		size_t box_index = i / 3 * 3 + j / 3;
		// check row, column, box numbers
		for (int t = 0; t < 9; t++)
		{
			if (!(row[i][t] || col[j][t] || box[box_index][t]))
			{
				board[i][j] = '1' + t;
				row[i][t] = true;
				col[j][t] = true;
				box[box_index][t] = true;

				if (j == 8) {
					i++;
					j = 0;
				}
				else {
					j++;
				}

				// 试错，回溯
				if (!back_track(board, i, j)) {
					if (j != 0) {
						j--;
					}
					else {
						i--;
						j = 8;
					}
					board[i][j] = '.';
					row[i][t] = false;
					col[j][t] = false;
					box[box_index][t] = false;

				}
				else return true;
			}
		}
		return false;

	}

};

int main() {
	vector<vector<char> > board(9);

	//string strs[9] = { "53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79" };
	string strs[9] = { "..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.." };
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
