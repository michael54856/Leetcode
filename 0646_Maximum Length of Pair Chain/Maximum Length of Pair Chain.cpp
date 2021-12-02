class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end(),comp);
        
        int len = pairs.size();
            
        int ans = 1;

        int last_1 = pairs[0][1];
        
        for(int i = 0; i < len; i++)
        {
            
            if(pairs[i][1] < last_1)
            {
                last_1 = pairs[i][1];
            }
            else if(last_1 < pairs[i][0])
            {
                ans++;
                last_1 = pairs[i][1];
            }
        }
        
        
        return ans;
        
        
    }
};