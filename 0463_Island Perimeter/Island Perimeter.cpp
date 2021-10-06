class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans += 4;
                    if(i-1 >= 0)
                    {
                        ans -= grid[i-1][j];
                    }
                    if(i+1 < row)
                    {
                        ans -= grid[i+1][j];
                    }
                    if(j-1 >= 0)
                    {
                        ans -= grid[i][j-1];
                    }
                    if(j+1 < col)
                    {
                        ans -= grid[i][j+1];
                    }
                }
            }
        }
        return ans;
    }
};