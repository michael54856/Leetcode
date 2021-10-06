class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int t = abs(nums[i]);
            if(nums[t-1] < 0)
            {
                ans.push_back(t);
            }
            else
            {
                nums[t-1] *= -1;
            }
        }
        return ans;
        
    }
};