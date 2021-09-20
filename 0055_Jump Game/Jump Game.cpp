class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int len = nums.size();
        int maxReach = 0;
        for(int i = 0; i < len && i <= maxReach; i++)
        {
            if(nums[i]+i > maxReach)
            {
                maxReach = nums[i]+i;
            }
            if(maxReach >= len-1)
            {
                return true;
            }
        }
        return false;
    }
};