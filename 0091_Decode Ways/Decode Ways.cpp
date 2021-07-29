class Solution
{
public:
    int numDecodings(string s)
    {
        int dp[101] = {};
        int len = s.size();
        dp[len] = 1;

        //do dp[len-1] first
        if(s[len-1] == '0')
        {
            dp[len-1] = 0;
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
            else if(s[i] == '1')
            {
                dp[i] = dp[i+1] + dp[i+2];
            }
            else if(s[i] == '2')
            {
                if(s[i+1] >= '0' && s[i+1] <= '6')
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
        }
        return dp[0];
    }

};