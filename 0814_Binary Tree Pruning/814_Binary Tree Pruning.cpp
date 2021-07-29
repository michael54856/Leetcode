class Solution
{
public:
    int Trim(TreeNode* root)
    {
        int counter = root->val;
        if(root->left)
        {
            int a = Trim(root->left);
            if(a == 0)
            {
                root->left = nullptr;
            }
            counter += a;
        }
        if(root->right)
        {
            int a = Trim(root->right);
            if(a == 0)
            {
                root->right = nullptr;
            }
            counter += a;
        }
        return counter;
    }

    TreeNode* pruneTree(TreeNode* root)
    {
        int a = Trim(root);
        if(a == 0)
        {
            return nullptr;
        }
        return root;
    }
};