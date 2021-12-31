class Solution
{
public:
    int ans = 0;
    struct info
    {
        info(int min_,int max_)
        {
            minVal = min_;
            maxVal = max_;
        }
        int minVal;
        int maxVal;
    };
    info DFS(TreeNode* root)
    {
        int maxVal = root->val;
        int minVal = root->val;
        if(root->left)
        {
            info leftInfo = DFS(root->left);
            if(leftInfo.maxVal > maxVal)
            {
                maxVal = leftInfo.maxVal;
            }
            if(leftInfo.minVal < minVal)
            {
                minVal = leftInfo.minVal;
            }
        }
        if(root->right)
        {
            info rightInfo = DFS(root->right);
            if(rightInfo.maxVal > maxVal)
            {
                maxVal = rightInfo.maxVal;
            }
            if(rightInfo.minVal < minVal)
            {
                minVal = rightInfo.minVal;
            }
        }
        if(abs(root->val-maxVal) > ans)
        {
            ans = abs(root->val-maxVal);
        }
        if(abs(root->val-minVal) > ans)
        {
            ans = abs(root->val-minVal);
        }
        info temp(minVal,maxVal);
        return temp;
    }
    int maxAncestorDiff(TreeNode* root)
    {
        DFS(root);
        return ans;
    }
};