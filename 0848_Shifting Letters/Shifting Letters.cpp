class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts)
    {
        int len = shifts.size();
        long long int *prefixSum = new long long int[len];
        prefixSum[len-1] = shifts[len-1];
        for(int i = len-2; i >= 0; i--)//construct prefix sum
        {
            prefixSum[i] = prefixSum[i+1]+shifts[i];
        }

        for(int i = 0; i < len; i++)
        {
            s[i] = (char)(((prefixSum[i]+s[i]-'a')%26)+'a');
        }
        return s;

    }
};