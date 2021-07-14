class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        
        int count_ = 0;
        int last = -1000;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != last)
            {
                last = nums[i];
                nums[count_] = nums[i];
                count_++;
            }
        }
        return count_;
    }
};