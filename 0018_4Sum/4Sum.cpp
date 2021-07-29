class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int len = nums.size();
        vector<vector<int>> ans;
        if(len < 4)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        long long int t1;
        long long int t2;
        t1 = ((long long int)(nums[0])) * 4;
        t2 = ((long long int)(nums[len-1]))*4;
        if(t1 > target || t2 < target)
        {
            return ans;
        }
        int last_1 = -2147483647;
        for(int i = 0; i <= len-4; i++)
        {
            if(nums[i] == last_1)
            {
                continue;
            }
            last_1 = nums[i];

            int last_2 = -2147483647;
            for(int j = i+1; j <= len-3; j++)
            {
                if(nums[j] == last_2)
                {
                    continue;
                }
                last_2 = nums[j];

                int sum = target-nums[i]-nums[j];
                int left = j+1;
                int right = len-1;
                while(left < right)
                {
                    if(nums[left]+nums[right] == sum)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int t = nums[left];
                        while(left < right && nums[left] == t)
                        {
                            left++;
                        }
                        t = nums[right];
                        while(left < right && nums[right] == t)
                        {
                            right--;
                        }
                    }
                    else if(nums[left]+nums[right] < sum)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;

    }
};