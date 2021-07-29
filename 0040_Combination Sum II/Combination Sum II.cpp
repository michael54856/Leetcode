class Solution {
public:
    vector<vector<int>> ans;
    int numCount[51] = {};
    int sortedArray[51];
    int x = 0;
    void dfs(int target, vector<int>& currentVector, int currentSum, int pos)
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
        if(pos == x)
        {
            return;
        }
        dfs(target,currentVector,currentSum,pos+1);
        for(int i = 0, len = numCount[sortedArray[pos]]; i < len && currentSum < target; i++)
        {
            currentVector.push_back(sortedArray[pos]);
            currentSum += sortedArray[pos];
            dfs(target,currentVector,currentSum,pos+1);
        }
        while(currentVector.empty() == false && currentVector.back() == sortedArray[pos])
        {
            currentSum -= sortedArray[pos];
            currentVector.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
     {
         int len = candidates.size();
         for(int i = 0; i < len; i++)
         {
             numCount[candidates[i]]++;
         }
         for(int i = 1; i <= 50; i++)
         {
             if(numCount[i] != 0)
             {
                 sortedArray[x] = i;
                 x++;
             }
         }
         vector<int> currentVector;
         int currentSum = 0;
         dfs(target,currentVector,currentSum,0);
         return ans;
    }
};