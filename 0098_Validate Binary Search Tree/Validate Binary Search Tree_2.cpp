class Solution
{
public:
    bool findValid(TreeNode* root, long long int min_, long long int max_)
    {
        if(root == nullptr)
        {
            return true;
        }
        if(root->val <= min_ || root->val >= max_)
        {
            return false;
        }
        return (findValid(root->left,min_,root->val) && findValid(root->right,root->val,max_));
    }
    bool isValidBST(TreeNode* root)
    {
        return findValid(root,-2147483649,2147483648);
    }
};