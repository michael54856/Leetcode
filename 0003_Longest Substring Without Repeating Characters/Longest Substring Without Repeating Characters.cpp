class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();

        if(s.size() == 0)//去處理空字串的情況
        {
            return 0;
        }
        if(s.size() == 1)
        {
            return 1;
        }

        int pos[128];
        for(int i = 0; i < 128; i++)
        {
            pos[i] = -1;
        }

        int ans = 0;
        int pivot = 0;

        for(int i = 0; i < len; i++)
        {
            if(pos[s[i]] >= pivot)//上個character在pivot右邊
            {

                if(i - pivot > ans)
                {
                    ans = i - pivot;
                }
                pivot = pos[s[i]]+1;
                pos[s[i]] = i;
            }
            else//上個character在pivot左邊
            {
                pos[s[i]] = i;
            }
        }
        if(len - pivot > ans)
        {
            ans = len - pivot;
        }
        
        
        return ans;
    }
};
