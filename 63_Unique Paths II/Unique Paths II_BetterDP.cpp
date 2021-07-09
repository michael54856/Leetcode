class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int dp[101] = {};
        
        dp[0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            if(obstacleGrid[i][0] == 1)//如果一開始就是障礙,代表整列都不可能從左邊來
            {
                dp[0] = 0;
            }
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] += dp[j-1];//因為本來就保留上排的資訊,只要加左邊即可
                }
                
            }
        }
        
        return dp[n-1];


    }
};