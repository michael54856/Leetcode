class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n,0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    int distance = 2000000000;
                    if(i-1 >= 0)//up
                    {
                        if(ans[i-1][j]+1 < distance)
                        {
                            distance = ans[i-1][j]+1;
                        }
                    }
                    if(j-1 >= 0)//left
                    {
                         if(ans[i][j-1]+1 < distance)
                        {
                            distance = ans[i][j-1]+1;
                        }
                    }
                    ans[i][j] = distance;
                }
            }
        }

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    int distance = 2000000000;
                    if(i+1 < m)//down
                    {
                        if(ans[i+1][j]+1 < distance)
                        {
                            distance = ans[i+1][j]+1;
                        }
                    }
                    if(j+1 < n)//right
                    {
                         if(ans[i][j+1]+1 < distance)
                        {
                            distance = ans[i][j+1]+1;
                        }
                    }
                    if(ans[i][j] > distance)
                    {
                        ans[i][j] = distance;
                    }
                }
            }
        }
        return ans;
    }
};