class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int len = nums.size();
        int even_pointer = 0;
        int odd_pointer = 1;

        while(true)
        {
            while(even_pointer < len)
            {
                if((nums[even_pointer] & 1) == 1)
                {
                    break;
                }
                even_pointer += 2;
            }
            if(even_pointer > len-1)
            {
                break;
            }
            while(odd_pointer < len)
            {
                if((nums[odd_pointer] % 2) == 0)
                {
                    break;
                }
                odd_pointer += 2;
            }
            if(odd_pointer > len-1)
            {
                break;
            }
            swap(nums[odd_pointer], nums[even_pointer]);

        }
        return nums;
    }
};