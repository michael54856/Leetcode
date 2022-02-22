class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int len = columnTitle.size();
        int sum = 0;
        long long int t = 1;
        for(int i = len-1; i >= 0; i--)
        {
            sum += (columnTitle[i]-'A'+1)*t;
            t *= 26;
        }
        return sum;
    }
    
};