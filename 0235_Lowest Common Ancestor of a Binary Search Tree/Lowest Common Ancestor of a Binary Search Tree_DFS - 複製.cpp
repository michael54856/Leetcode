class Solution
{
public:
    TreeNode *target1;
    TreeNode *target2;
    TreeNode *ans = nullptr;
    int dfs(TreeNode* root)
    {
        if(ans != nullptr)
        {
            return 0;
        }

        int found = 0;
        if(root == target1)
        {
            found++;
        }
        if(root == target2)
        {
            found++;
        }

        int a = 0;
        int b = 0;
        if(root->left)
        {
            a = dfs(root->left);
        }
        if(root->right)
        {
            b = dfs(root->right);
        }

        if(a+b+found == 2)
        {
            ans = root;
        }

        return a+b+found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        target1 = p;
        target2 = q;
        dfs(root);
        return ans;
    }
};