class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int row = mat.size();
        int column = mat[0].size();
        if(r*c != row*column)
        {
            return mat;
        }

        int m = 0;
        int n = 0;

        vector<vector<int>> ans(r);
        for(int i = 0; i < r; i++)
        {
            ans[i] = vector<int>(c);
            for(int j = 0; j < c; j++)
            {
                ans[i][j] = mat[m][n];
                n++;
                if(n == column)
                {
                    m++;
                    n = 0;
                }
            }
        }

        return ans;
    }
};