class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int another = target - nums[i];
            if(m.find(another) != m.end())
            {
                ans.push_back(m[another]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};