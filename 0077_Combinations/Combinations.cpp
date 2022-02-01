class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int count, int last, int &n, int &k)
    {
        if(count == k)
        {
            ans.push_back(temp);
            return;
        }
        int bound = n-(k-count)+1;
        for(int i = last+1; i <= bound; i++)
        {
            temp.push_back(i);
            dfs(count+1,i,n,k);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k)
    {
        dfs(0,0,n,k);
        return ans;
    }
};