class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int hash_[10001] = {};
        int len = nums.size();
        int all = (1+len)*len/2;
        int sum = 0;
        vector<int> ans;
        for(int i = 0; i < len; i++)
        {
            if(hash_[nums[i]] == 1)
            {
                ans.push_back(nums[i]);
            }
            hash_[nums[i]] = 1;
            sum += nums[i];
        }
        ans.push_back(all-sum+ans[0]);
        return ans;
    }
};