class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int len = s.size();
        int oneLeft[100000] = {};
        int zeroRight[100000] = {};
        int zeroCount = 0;
        int oneCount = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '1')
            {
                oneCount++;
            }
            oneLeft[i] = oneCount;
            
            if(s[len-i-1] == '0')
            {
                zeroCount++;
            }
            zeroRight[len-i-1] = zeroCount;
        }
        int ans = 2147483647;
        if(oneLeft[len-1] < ans)
        {
            ans = oneLeft[len-1];
        }
        if(zeroRight[0] < ans)
        {
            ans = zeroRight[0];
        }
        for(int i = 0; i < len-1; i++)//left all change to 0, right all change to 1
        {
            int sum = oneLeft[i] + zeroRight[i+1];
            if(sum < ans)
            {
                ans = sum;
            }
        }
        return ans;
    }
};