class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void dfs(vector<int>& candidates, int target, vector<int>& currentVector, int currentSum, int pos)
    {
        if(currentSum > target)
        {
            return;
        }
        if(currentSum == target)
        {
            ans.push_back(currentVector);
            return;
        }
        if(pos >= len)
        {
            return;
        }

        dfs(candidates,target,currentVector,currentSum,pos+1);
        while(currentSum < target)
        {
            currentVector.push_back(candidates[pos]);
            currentSum += candidates[pos];
            dfs(candidates,target,currentVector,currentSum,pos+1);
        }
        while(currentVector.empty() == false && currentVector.back() == candidates[pos])
        {
            currentSum -= candidates[pos];
            currentVector.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        len = candidates.size();
        vector<int> currentVector;
        int currentSum = 0;
        dfs(candidates,target,currentVector,currentSum,0);
        return ans;
    }
};