class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int len = strs.size();
        string ans = strs[0];
        
        for(int i = 1; i < len; i++)
        {
            string temp = "";
            int bound = min(ans.size(),strs[i].size());
            
            for(int j  = 0; j < bound; j++)
            {
                if(ans[j] != strs[i][j])
                {
                    break;
                }
                temp += ans[j];
            }
            ans = temp;
        }
        return ans;
        
    }
};