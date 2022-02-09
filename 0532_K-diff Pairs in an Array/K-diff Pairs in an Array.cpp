class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<int,int> myMap;
        int len = nums.size();
        int ans = 0;
        
        if(k == 0)
        {
            for(int i = 0; i < len; i++)
            {
                int val = ++myMap[nums[i]];
                if(myMap[nums[i]] == 2)
                {
                    ans++;
                }
            }
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                if(myMap[nums[i]] == 0)
                {
                     myMap[nums[i]] = 1;
                    if(myMap[nums[i]-k] == 1)
                    {
                        ans++;
                    }
                    if(myMap[nums[i]+k] == 1)
                    {
                        ans++;
                    }
                }

            }
        }
        
        
        return ans;
    }
};