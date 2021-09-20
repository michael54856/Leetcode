class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        int ans = nums[0];
        for(int i = 1; i < len; i++)
        {
            nums[i] = max(nums[i],nums[i]+nums[i-1]);
            if(nums[i] > ans)
            {
                ans = nums[i];
            }
        }
        return ans;
    }
};