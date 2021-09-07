class Solution
{
public:
    vector<TreeNode*> generateTreeList(int minVal, int maxVal)
    {
        vector<TreeNode*> returnList;
        if(minVal >  maxVal)
        {
            returnList.push_back(nullptr);
            return returnList;
        }

        for(int i = minVal; i <= maxVal; i++)
        {
            vector<TreeNode*> left = generateTreeList(minVal, i-1); //construct left subTree
            vector<TreeNode*> right = generateTreeList(i+1, maxVal); //construct right subTree

            int len_1 = left.size();
            int len_2 = right.size();
            
            

            for(int j = 0; j < len_1; j++)
            {
                for(int k = 0; k < len_2; k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];

                    returnList.push_back(root);
                }
            }
        }

        return returnList;


    }
    vector<TreeNode*> generateTrees(int n)
    {
        return generateTreeList(1,n);
    }
};