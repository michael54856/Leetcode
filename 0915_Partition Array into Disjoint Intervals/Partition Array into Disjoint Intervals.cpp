class Solution {
public:
    int partitionDisjoint(vector<int>& nums)
    {
        int rightMin[30000];
        int len = nums.size();
        int min_ = 2147483647;
        int max_ = -1;
        for(int i = len-1; i >=0 ; i--)
        {
            if(nums[i] < min_)
            {
                min_ = nums[i];
            }
            rightMin[i] = min_;
        }
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > max_)
            {
                max_ = nums[i];
            }
            if(max_ <= rightMin[i+1])
            {
                return i+1;
            }
        }
        return 0;


    }
};