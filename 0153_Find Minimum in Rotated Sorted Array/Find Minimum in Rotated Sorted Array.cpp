class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size()-1;
        if(r == 0)
        {
            return nums[0];
        }
        if(nums[0] < nums[r])
        {
            return nums[0];
        }
        
        while(l+1 < r)
        {
            int mid = (r+l) >> 1;
            if(nums[l] < nums[mid])//往右
            {
                l = mid;
            }
            if(nums[mid] < nums[r])//往左
            {
                r = mid;
            }
        }
        return nums[r];
    }
};