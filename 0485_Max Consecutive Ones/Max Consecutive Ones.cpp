class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int len = nums.size();
        int counter = 0;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == 0)
            {
                if(counter > ans)
                {
                    ans = counter;
                }
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        if(counter > ans)
        {
            ans = counter;
        }
        return ans;
        
    }
};