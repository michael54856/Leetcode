class Solution
{
public:
    int ans = 0;
    void dfs(TreeNode* root,int num)
    {
        if(num > ans)
        {
            ans = num;
        }
        if(root->left)
        {
            dfs(root->left,num+1);
        }
        if(root->right)
        {
            dfs(root->right,num+1);
        }
    }
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        dfs(root,1);
        return ans;
    }
};