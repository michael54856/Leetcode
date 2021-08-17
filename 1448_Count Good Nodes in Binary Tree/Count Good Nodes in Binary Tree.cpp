class Solution
{
public:
    int ans = 0;
    void dfs(TreeNode* root, int cuurentMax)
    {
        if(cuurentMax > root->val)
        {
            if(root->left)
            {
                dfs(root->left,cuurentMax);
            }
            if(root->right)
            {
                dfs(root->right,cuurentMax);
            }
        }
        else
        {
            ans++;
            if(root->left)
            {
                dfs(root->left,root->val);
            }
            if(root->right)
            {
                dfs(root->right,root->val);
            }
        }
    }
    int goodNodes(TreeNode* root)
    {
        dfs(root,-2147483647);
        return ans;
    }
};