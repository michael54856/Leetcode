class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        int *dp = new int[len];
        int dpSize = 1;
        dp[0] = nums[0];

        for(int i = 1; i < len; i++)
        {
            if(nums[i] > dp[dpSize-1])//bigger than last
            {
                dp[dpSize] = nums[i];
                dpSize++;
            }
            else
            {
                auto it = lower_bound(dp,dp+dpSize,nums[i]);//find first >= nums[i]
                *it = nums[i];
            }
        }

        return dpSize;
    }
};