struct info
{
    int horizontalContinue;
    int verticalContinue;
    int squareSize;
};


class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        //dp[][] record vertical info
        int m = matrix.size();
        int n = matrix[0].size();

        info **dp = new info*[m];
        for(int i = 0; i < m; i++)
        {
            dp[i] = new info[n];
        }

        int ans = 0;

        if(matrix[0][0] == '0')//check top-left corner
        {
            dp[0][0].horizontalContinue = 0;
            dp[0][0].verticalContinue = 0;
            dp[0][0].squareSize = 0;
        }
        else
        {
            dp[0][0].horizontalContinue = 1;
            dp[0][0].verticalContinue = 1;
            dp[0][0].squareSize = 1;
            ans = 1;
        }

        for(int i = 1; i < n; i++)//do the first row
        {
            if(matrix[0][i] == '0')
            {
                dp[0][i].horizontalContinue = 0;
                dp[0][i].verticalContinue = 0;
                dp[0][i].squareSize = 0;
            }
            else
            {
                dp[0][i].horizontalContinue = 1 + dp[0][i-1].horizontalContinue;
                dp[0][i].verticalContinue = 1;
                dp[0][i].squareSize = 1;
                ans = 1;
            }
        }

        for(int i = 1; i < m; i++)//do the first column
        {
            if(matrix[i][0] == '0')
            {
                dp[i][0].horizontalContinue = 0;
                dp[i][0].verticalContinue = 0;
                dp[i][0].squareSize = 0;
            }
            else
            {
                dp[i][0].verticalContinue = 1 + dp[i-1][0].verticalContinue;
                dp[i][0].horizontalContinue = 1;
                dp[i][0].squareSize = 1;
                ans = 1;
            }
        }

        for(int i = 1; i < m; i++)//calculate the rest of the row
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == '0')
                {
                    dp[i][j].horizontalContinue = 0;
                    dp[i][j].verticalContinue = 0;
                    dp[i][j].squareSize = 0;
                }
                else
                {
                    dp[i][j].horizontalContinue = 1 + dp[i][j-1].horizontalContinue;
                    dp[i][j].verticalContinue = 1 + dp[i-1][j].verticalContinue;
                    int t = min(dp[i][j].horizontalContinue, dp[i][j].verticalContinue);
                    int last = dp[i-1][j-1].squareSize;
                    if(last >= t)
                    {
                        dp[i][j].squareSize = t;
                    }
                    else
                    {
                        dp[i][j].squareSize = last+1;
                    }

                    if(dp[i][j].squareSize > ans)
                    {
                         ans = dp[i][j].squareSize;
                    }

                }
            }

        }

        return ans* ans;

    }
};