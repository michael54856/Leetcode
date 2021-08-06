class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root == nullptr)
        {
            return ans;
        }
        q.push(root);

        while(q.empty() == false)
        {
            int nodeCount = q.size();
            Node* temp;
            vector<int> levelList;
            for(int i = 0; i < nodeCount; i++)
            {
                temp = q.front();
                q.pop();
                levelList.push_back(temp->val);

                int len = (temp->children).size();
                for(int j = 0; j < len; j++)
                {
                    q.push(temp->children[j]);
                }
            }
            ans.push_back(levelList);
        }
        return ans;
    }
};