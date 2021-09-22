class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 1)
        {
            return nums[0];
        }
        int totalSum = nums[0];

        int *maxDP = new int[len];
        maxDP[0] = nums[0];
        int maxSum = maxDP[0];

        int *minDP = new int[len];
        minDP[0] = nums[0];
        int minSum = minDP[0];

        for(int i = 1; i < len-1; i++)
        {
            maxDP[i] = max(nums[i],nums[i]+maxDP[i-1]);
            minDP[i] = min(nums[i],nums[i]+minDP[i-1]);
            if(maxDP[i] > maxSum)
            {
                maxSum = maxDP[i];
            }
            if(minDP[i] < minSum)
            {
                minSum = minDP[i];
            }

            totalSum += nums[i];
        }
        maxDP[len-1] = max(nums[len-1],nums[len-1]+maxDP[len-2]);
        if(maxDP[len-1] > maxSum)
        {
            maxSum = maxDP[len-1];
        }
        totalSum += nums[len-1];

        return max(maxSum, totalSum-minSum);

    }
};