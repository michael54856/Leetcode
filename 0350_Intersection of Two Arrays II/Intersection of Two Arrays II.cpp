class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        int counter[1001] = {};
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        for(int i = 0; i < len1; i++)
        {
            counter[nums1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < len2; i++)
        {
            if(counter[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                counter[nums2[i]]--;
            }
        }
        
        return ans;
    }
};