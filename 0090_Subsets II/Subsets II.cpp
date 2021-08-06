class Solution {
public:
    vector<vector<int>> allAns;
    int len;
    void dfs(vector<int>& nums, vector<int>& ans, int pos)
    {
        if(pos == len-1)
        {
            return;
        }
        bool haveChosen[21] = {};
        for(int i = pos+1; i < len; i++)
        {
            if(haveChosen[nums[i]+10] == false)
            {
                ans.push_back(nums[i]);
                allAns.push_back(ans);
                dfs(nums,ans,i);
                ans.pop_back();
                haveChosen[nums[i]+10] = true;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        allAns.push_back(ans);
        dfs(nums,ans,-1);
        return allAns;

    }
};