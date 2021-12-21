class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        int *dp = new int[len];
        int ans = 1;
        dp[0] = 1;
        for(int i = 1; i < len; i++)
        {
            int t = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[j] > t)
                    {
                        t = dp[j];
                    }
                }
            }
            dp[i] = 1+t;
            if(dp[i] > ans)
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};
