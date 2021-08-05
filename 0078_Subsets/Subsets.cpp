class Solution {
public:
    vector<vector<int>> allAns;
    int len;
    void dfs(vector<int>& nums, vector<int>& ans, int pos)
    {

        for(int i = pos+1; i < len; i++)
        {
            ans.push_back(nums[i]);
            allAns.push_back(ans);
            dfs(nums,ans,i);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        len = nums.size();
        vector<int> ans;
        allAns.push_back(ans);
        dfs(nums,ans,-1);
        return allAns;

    }
};