class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int length = intervals[0][1];
        int ans = len;
        for(int i = 1; i < len; i++)
        {
            if(intervals[i][1] <= length)
            {
                ans--;
            }
            else
            {
                length = intervals[i][1];
            }
        }
        return ans;
    }
};