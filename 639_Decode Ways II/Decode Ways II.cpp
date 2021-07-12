class Solution
{
public:
    long long int dp[100001] = {};
    int numDecodings(string s)
    {
        int len = s.size();
        dp[len] = 1;

        //do dp[len-1] first
        if(s[len-1] == '0')
        {
            dp[len-1] = 0;
        }
        else if(s[len-1] == '*')
        {
            dp[len-1] = 9;
        }
        else
        {
            dp[len-1] = 1;
        }


        for(int i = len-2; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
            }
            else if(s[i] == '*')
            {
                long long int total = 9*dp[i+1];
                if(s[i+1] == '*')
                {
                    total += 9*dp[i+2];//when * = 1, we can have 2 digits
                    total += 6*dp[i+2];//when * = 2, we can have 2 digits
                }
                else
                {
                    total += dp[i+2];//when * = 1, we can have 2 digits
                    if(s[i+1] >= '0' && s[i+1] <= '6')
                    {
                        total += dp[i+2];//when * = 1, we can have 2 digits
                    }
                }
                dp[i] = total;
            }
            else if(s[i] == '1')
            {
                if(s[i+1] == '*')
                {
                    dp[i] = dp[i+1] + (9*dp[i+2]);
                }
                else
                {
                    dp[i] = dp[i+1] + dp[i+2];
                }
            }
            else if(s[i] == '2')
            {
                if(s[i+1] == '*')
                {
                    dp[i] = dp[i+1] + (6*dp[i+2]);
                }
                else if(s[i+1] >= '0' && s[i+1] <= '6')
                {
                    dp[i] = dp[i+1] + dp[i+2];
                }
                else
                {
                    dp[i] = dp[i+1];
                }
            }
            else
            {
                dp[i] = dp[i+1];
            }
            dp[i] %= 1000000007;
        }
        return dp[0];
    }

};