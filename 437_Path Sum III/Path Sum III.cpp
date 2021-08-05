class Solution
{
public:
    int ans = 0;

    void dfs(TreeNode* root, int targetSum, long long int sum, unordered_map<long long int, int> &myMap)
    {
        sum += root->val;
        long long int x = sum - targetSum;
        if(myMap.find(x) != myMap.end())
        {
            ans += myMap[x];
        }

        if(myMap.find(sum) == myMap.end())
        {
            myMap[sum] = 1;
        }
        else
        {
            myMap[sum]++;
        }

        if(root->left)
        {
            dfs(root->left,targetSum,sum,myMap);
        }
        if(root->right)
        {
            dfs(root->right,targetSum,sum,myMap);
        }
        
        if(myMap[sum] == 1)
        {
            myMap.erase(sum);
        }
        else
        {
            myMap[sum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<long long int, int> myMap;
        myMap[0] = 1;
        if(root == nullptr)
        {
            return 0;
        }
        dfs(root,targetSum,0,myMap);
        return ans;
    }
};