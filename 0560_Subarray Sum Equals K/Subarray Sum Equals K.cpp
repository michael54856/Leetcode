class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int,int> myMap;
        unordered_map<int,int>::iterator iter;
        int len = nums.size();
        int *dp = new int[len];
        int ans = 0;
        dp[0] = nums[0];
        if(dp[0] == k)
        {
            ans++;
        }
        myMap[dp[0]]++;
        for(int i = 1; i < len; i++)
        {
            dp[i] = nums[i]+dp[i-1];
            if(dp[i] == k)
            {
                ans++;
            }
            int target = dp[i]-k;
            iter = myMap.find(target);
            if(iter != myMap.end())
            {
                ans += iter->second;
            }
            myMap[dp[i]]++;
        }
        return ans;
    }
};