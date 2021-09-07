class Solution
{
public:
    bool haveSeen[9][9] = {};
    vector<TreeNode*> dp[9][9];

    vector<TreeNode*> generateTreeList(int minVal, int maxVal)
    {

        vector<TreeNode*> returnList;
        if(minVal >  maxVal)
        {
            returnList.push_back(nullptr);
            return returnList;
        }

        if(haveSeen[minVal][maxVal] == true)
        {
            return dp[minVal][maxVal];
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

        haveSeen[minVal][maxVal] = true;
        dp[minVal][maxVal] = returnList;
        return returnList;


    }
    vector<TreeNode*> generateTrees(int n)
    {

        for(int i = 1; i <= 8; i++)
        {
            vector<TreeNode*> returnList;
            haveSeen[i][i] = true;
            returnList.push_back(new TreeNode(i));
            dp[i][i] = returnList;
        }
        return generateTreeList(1,n);
    }
};