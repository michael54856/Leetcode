class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        int rowMin = m;
        int colMin = n;

        int len = ops.size();

        for(int i = 0; i < len; i++)
        {
            if(ops[i][0] < rowMin)
            {
                rowMin = ops[i][0];
            }
            if(ops[i][1] < colMin)
            {
                colMin = ops[i][1];
            }
        }
        return rowMin*colMin;
    }
};