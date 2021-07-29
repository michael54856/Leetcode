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
        bool haveSwaped[21] = {};
        for(int i = pos; i < len; i++)
        {
            if(haveSwaped[nums[i]+10] == false)
            {
                swap(nums[pos],nums[i]);
                dfs(nums,pos+1);
                swap(nums[pos],nums[i]);
                haveSwaped[nums[i]+10] = true;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        len = nums.size();
        dfs(nums,0);
        return ans;
    }
};