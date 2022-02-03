class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int len = nums1.size();
        unordered_map<int,int> myMap;
        unordered_map<int,int>::iterator iter;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                myMap[nums3[i]+nums4[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                iter = myMap.find(-(nums1[i]+nums2[j]));
                if(iter != myMap.end())
                {
                    ans += iter->second;
                }
            }
        }
        return ans;


    }
};