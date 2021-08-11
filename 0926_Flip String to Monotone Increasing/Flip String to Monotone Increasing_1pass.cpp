class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int len = s.size();
        int ans = 0;
        int count1 = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '1')
            {
                count1++;
            }
            else
            {
                ans = min(ans+1,count1);//flip last 0, or make the string all 0
            }
        }
        return ans;
    }
};