class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int sLen = s.size();
        int dictLen = wordDict.size();

        bool *dp = new bool[sLen]();

        for(int i = 0; i < sLen; i++)
        {
            for(int j = 0; j < dictLen; j++)
            {
                int len = wordDict[j].size();
                if(i+1 >= len)
                {
                    bool allSame = true;
                    for(int k = 0; k < len; k++)
                    {
                        if(s[i-k] != wordDict[j][len-1-k])
                        {
                            allSame = false;
                            break;
                        }
                    }
                    if(allSame == true)
                    {
                        if(i+1 == len)
                        {
                            dp[i] = true;
                        }
                        else
                        {
                            if(dp[i] == false)
                            {
                                dp[i] = dp[i-len];
                            }
                            
                        }
                    }
                }
            }
        }

        return dp[sLen-1];

    }
};