class Solution
{
public:
    void constructTree(int left, int right, vector<int>& nums, TreeNode* root)
    {
        int mid = (left+right) / 2;

        if(left < mid)
        {
            int leftPartMid = (left+mid-1)/2;
            root->left = new TreeNode(nums[leftPartMid]);
            constructTree(left,mid-1,nums,root->left);
        }
        if(mid < right)
        {
            int rightPartMid = (right+mid+1)/2;
            root->right = new TreeNode(nums[rightPartMid]);
            constructTree(mid+1,right,nums,root->right);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int len = nums.size();
        int mid = (len-1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        constructTree(0,len-1,nums,root);
        return root;
    }
};