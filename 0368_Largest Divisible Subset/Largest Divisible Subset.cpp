class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> m;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int another = target - nums[i];
            if(m.find(another) != m.end())
            {
                return {m[another],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};