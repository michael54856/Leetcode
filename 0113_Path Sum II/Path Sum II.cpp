class Solution
{
public:
    bool haveAns = false;
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, int sum, vector<int> &sumList)
    {
        sum += root->val;

        sumList.push_back(root->val);

        if(sum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(sumList);
        }

        if(root->left)
        {
            dfs(root->left,targetSum,sum,sumList);
        }
        if(root->right)
        {
            dfs(root->right,targetSum,sum,sumList);
        }

        sumList.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> sumList;
        if(root == nullptr)
        {
            return ans;
        }
        dfs(root,targetSum,0,sumList);
        return ans;
    }
};