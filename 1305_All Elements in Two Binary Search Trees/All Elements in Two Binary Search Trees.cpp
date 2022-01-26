class Solution
{
public:
    int a[5000];
    int aLen = 0;
    int b[5000];
    int bLen = 0;
    void dfs_1(TreeNode* root)
    {
        if(root->left)
        {
            dfs_1(root->left);
        }
        a[aLen++] = root->val;
        if(root->right)
        {
            dfs_1(root->right);
        }
    }
    void dfs_2(TreeNode* root)
    {
        if(root->left)
        {
            dfs_2(root->left);
        }
        b[bLen++] = root->val;
        if(root->right)
        {
            dfs_2(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ans;
        if(root1)
        {
            dfs_1(root1);
        }
        if(root2)
        {
            dfs_2(root2);
        }


        int i = 0;
        int j = 0;
        while(i < aLen && j < bLen)
        {
            if(a[i] < b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i < aLen)
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j < bLen)
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};
