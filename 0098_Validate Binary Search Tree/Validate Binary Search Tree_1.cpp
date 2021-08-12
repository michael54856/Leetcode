struct info
{
    info(int a, int b) : min_{a}, max_{b}
    {
    }
    int min_;
    int max_;
};

class Solution
{
public:
    bool ans = true;
    info findValue(TreeNode* root)
    {
        info returnInfo = info(root->val,root->val);
        if(root->left)
        {
            info temp = findValue(root->left);
            if(temp.max_ >= root->val)
            {
                ans = false;
            }
            else
            {
                if(temp.max_ > returnInfo.max_)
                {
                    returnInfo.max_ = temp.max_;
                }
                if(temp.min_ < returnInfo.min_)
                {
                    returnInfo.min_ = temp.min_;
                }
            }
        }
        if(root->right && ans == true)
        {
            info temp = findValue(root->right);
            if(temp.min_ <= root->val)
            {
                ans = false;
            }
            else
            {
                if(temp.max_ > returnInfo.max_)
                {
                    returnInfo.max_ = temp.max_;
                }
                if(temp.min_ < returnInfo.min_)
                {
                    returnInfo.min_ = temp.min_;
                }
            }
        }
        return returnInfo;
    }
    bool isValidBST(TreeNode* root)
    {
        info temp(1,1);
        if(root->left)
        {
            temp = findValue(root->left);
            if(temp.max_ >= root->val)
            {
                ans = false;
            }
        }
        if(root->right && ans == true)
        {
            temp = findValue(root->right);
            if(temp.min_ <= root->val)
            {
                ans = false;
            }
        }
        return ans;
    }
};