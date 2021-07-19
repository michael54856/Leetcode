class Solution
{
public:
    TreeNode* findAns(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val < p->val)
        {
            return findAns(root->right, p,q);
        }
        else if(root->val > q->val)
        {
            return findAns(root->left, p,q);
        }
        else
        {
            return root;
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(p->val > q->val)
        {
            swap(p,q);
        }
        return findAns(root,p,q);
    }
};