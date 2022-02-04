class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        int len = nums.size();
        int *arr = new int[len*2+1](); //-4 -3 -2 -1 0 1 2 3 4
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == 0)
            {
                sum--;
            }
            else
            {
                sum++;
            }
            
            if(sum == 0)
            {
                ans = i+1;
            }
            else
            {
                if(arr[sum+len] == 0)
                {
                    arr[sum+len] = i+1;
                }
                else
                {
                    ans = max(ans,i-arr[sum+len]+1);
                }
            }

            
        }


        return ans;
    }
};