class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void dfs(vector<int>& nums, int pos)
    {
        if(pos == len)
        {
            ans.push_back(nums);
        }
        for(int i = pos; i < len; i++)
        {
            swap(nums[pos],nums[i]);
            dfs(nums,pos+1);
            swap(nums[pos],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        len = nums.size();
        dfs(nums,0);
        return ans;
    }
};