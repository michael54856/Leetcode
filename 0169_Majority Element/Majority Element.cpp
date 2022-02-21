class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int len = nums.size();
        int target = nums[0];
        int counter = 1;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] == target)
            {
                counter++;
            }
            else
            {
                counter--;
                if(counter == 0)
                {
                    target = nums[i];
                    counter = 1;
                }
            }
        }
        return target;
    }
};