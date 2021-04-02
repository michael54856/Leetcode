class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        unordered_map<int, int>::iterator iter;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target - nums[i])
            {
                iter = m.find(nums[i]);
                if(iter != m.end())
                {
                    ans.push_back(iter->second);
                    ans.push_back(i);
                    return ans;
                }
            }

            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            if(t != nums[i])
            {
                iter = m.find(t);
                if(iter == m.end())//no such number
                {
                    continue;
                }
                else
                {
                    ans.push_back(i);
                    ans.push_back(iter->second);
                    break;
                }
            }
            else
            {
                continue;
            }
        }


        return ans;
    }
};