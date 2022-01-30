class Solution
{
public:
    void reverseVector(vector<int>& nums, int l , int r)
    {
        while(l < r)
        {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        int len = nums.size();
        k %= len;
        
        reverseVector(nums,0,len-1);
        reverseVector(nums,k,len-1);
        reverseVector(nums,0,k-1);
    }

};