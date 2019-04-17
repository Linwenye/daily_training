class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    // set line and column to INT_MIN
                    for (int k = 0; k < matrix[0].size(); ++k)
                    {
                        if (matrix[i][k] != 0) {
                            matrix[i][k] = INT_MIN;
                        }
                    }

                    for (int k = 0; k < matrix.size(); ++k)
                    {
                        if (matrix[k][j] != 0)
                        {
                            matrix[k][j] = INT_MIN;
                        }
                    }
                }
            }
        }

        // set zero
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == INT_MIN)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};