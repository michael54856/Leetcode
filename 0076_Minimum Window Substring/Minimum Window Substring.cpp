class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sCounting[128] = {};
        int tCounting[128] = {};
        int matchCount = 0;
        int totalCount = 0;
        int tLen = t.size();
        int sLen = s.size();
        string ans = "";
        int ansLen = 2147483647;
        for(int i = 0; i < tLen; i++)
        {
            tCounting[t[i]]++;
            totalCount++;
        }
        int l = 0;
        int r = 0;
        while(r < sLen)
        {
            if(tCounting[s[r]] > 0)//need to be calculated
            {
                if(sCounting[s[r]] < tCounting[s[r]])
                {
                    matchCount++;
                }
                sCounting[s[r]]++;
            }

            if(matchCount < totalCount)//keep finding
            {
                r++;
            }
            else
            {
                while(true)
                {
                    if(tCounting[s[l]] > 0)
                    {
                        if(sCounting[s[l]] > tCounting[s[l]])
                        {
                            sCounting[s[l]]--;
                            l++;
                        }
                        else if(sCounting[s[l]] == tCounting[s[l]])
                        {
                            if(r-l+1 < ansLen)
                            {
                                ans = s.substr(l,r-l+1);
                                ansLen = r-l+1;
                            }
                            sCounting[s[l]]--;
                            matchCount--;
                            l++;
                            r++;
                            break;
                        }
                        else
                        {
                            l++;
                        }
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }


        return ans;
    }
};