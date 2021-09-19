class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 1)
        {
            return nums[0];
        }
        if(len == 2)
        {
            return max(nums[0],nums[1]);
        }
        
        int *dp = new int[len];
        
        int ans;
        
        //first-pass
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        
        for(int i = 2; i < len-1; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        ans = dp[len-2];
        
        
        //second-pass
        dp[1] = nums[1];
        dp[2] = max(dp[1],nums[2]);
        
        for(int i = 3; i < len; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        ans = max(ans,dp[len-1]);
        
        return ans;
        
        
    }
};