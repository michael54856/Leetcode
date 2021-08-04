class Solution
{
public:
    bool haveAns = false;
    void dfs(TreeNode* root, int targetSum, int sum)
    {
        sum += root->val;

        if(sum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            haveAns = true;
            return;
        }

        if(root->left)
        {
            dfs(root->left,targetSum,sum);
        }
        if(haveAns == true)
        {
            return;
        }
        if(root->right)
        {
            dfs(root->right,targetSum,sum);
        }

    }
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
        {
            return false;
        }
        dfs(root,targetSum,0);
        return haveAns;
    }
};