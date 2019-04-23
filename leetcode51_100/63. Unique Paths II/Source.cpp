class Solution {

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0].empty()) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        long long **dp = new long long *[n];
        for(int i=0;i<n;i++){
            dp[i]=new long long[m]();
        }
        for(int i=0;i<n;i++){
            if (obstacleGrid[i][0]==0)
            {
                dp[i][0]=1;
            }
            else break;
        }
        for(int j=0;j<m;j++){
            if (obstacleGrid[0][j]==0)
            {
                dp[0][j]=1;
            }
            else break;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if (obstacleGrid[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
