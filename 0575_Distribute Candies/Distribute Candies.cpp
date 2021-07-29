class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        int len = candyType.size();
        unordered_set<int> type;
        for(int i = 0; i < len; i++)
        {
            type.insert(candyType[i]);
        }
        int a = type.size();
        int b = len/2;
        return min(a,b);
    }
};