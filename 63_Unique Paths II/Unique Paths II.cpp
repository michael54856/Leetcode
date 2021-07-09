class Solution
{
public:
    int dp[101][101];
    int dfs(vector<vector<int>>& obstacleGrid, int y, int x, int m, int n)
    {
        if(y >= 0 && y < m && x >= 0 && x < n)//in map
        {
            if(obstacleGrid[y][x] == 1)
            {
                return 0;
            }
            else
            {
                if(y == m-1 && x == n-1)
                {
                    return -1;
                }
                else if(dp[y][x] != -1)
                {
                    return dp[y][x];
                }
                else
                {
                    int t1 = dfs(obstacleGrid,y+1,x,m,n);
                    int t2 = dfs(obstacleGrid,y,x+1,m,n);
                    dp[y][x] = (t1+t2);
                    return dp[y][x];
                }
            }
        }
        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        
        int ans = dfs(obstacleGrid,0,0,m,n);
        return ans*-1;

    }
};