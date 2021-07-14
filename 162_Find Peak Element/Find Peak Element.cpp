class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 1)
        {
            return 0;
        }

        int right = len-1;
        int left = 0;
        int mid;
        while(right > left)
        {
            mid = (right+left) >> 1;
            if(nums[mid+1] > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
       return left;



    }
};