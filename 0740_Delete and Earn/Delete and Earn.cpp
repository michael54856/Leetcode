class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
     {
         int len = nums.size();
         int dp[10000];
         int numCount[20001] = {};
         int max_ = nums[0];
         
         for(int i = 0; i < len; i++)
         {
             numCount[nums[i]]++;
             if(nums[i] > max_)
             {
                 max_ = nums[i];
             }
         }
         
         dp[1] = numCount[1];
         dp[2] = max(dp[1],numCount[2]*2);
         
         for(int i = 3; i <= max_; i++)
         {
             dp[i] = max(dp[i-1],dp[i-2]+numCount[i]*i);
         }
         
         return dp[max_];
         
         
         
        
    }
};