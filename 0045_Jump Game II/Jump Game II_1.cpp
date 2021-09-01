class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 1)
        {
            return 0;
        }
        int *dp = new int[len]();
        int distance = 0;
        
        for(int i = 0; i < len; i++)
        {
            int t = i+nums[i];
            if(t >= len-1)
            {
                return dp[i]+1;
            }
            if(t > distance)//可以到更遠的地方
            {
                for(int j = t; j > distance; j--)
                {
                    dp[j] = dp[i]+1;
                }
                distance = t;
            }
        }
        return 0;

    }
};