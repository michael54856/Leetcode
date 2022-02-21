class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void dfs(vector<int>& candidates, int &target, vector<int>& tempAns, int pos, int sum)
    {
        if(sum == target)
        {
            ans.push_back(tempAns);
            return;
        }
        if(sum > target)
        {
            return;
        }
        
        for(int i = pos; i < len; i++)
        {
            tempAns.push_back(candidates[i]);
            dfs(candidates, target, tempAns, i, sum+candidates[i]);
            tempAns.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        len = candidates.size();
        vector<int> tempAns;
        dfs(candidates, target, tempAns, 0, 0);
        return ans;
    }
};