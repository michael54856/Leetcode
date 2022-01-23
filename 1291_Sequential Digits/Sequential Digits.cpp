class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int t = low;
        int lowDigits = 0;
        int highDigits = 0;

        while(t > 0)
        {
            lowDigits++;
            t /= 10;
        }
        t = high;
        while(t > 0)
        {
            highDigits++;
            t /= 10;
        }
        vector<int> ans;
        int dictionary[] = {1,2,3,4,5,6,7,8,9};

        for(int i = lowDigits; i <= highDigits; i++)
        {
            int leftPointer = 0;
            int rightPointer = i-1;

            while(rightPointer <= 8)
            {
                int mul = 1;
                int sum = 0;
                for(int j = rightPointer; j >= leftPointer; j--)
                {
                    sum += mul*dictionary[j];
                    mul *= 10;
                }
                if(low <= sum && sum <= high)
                {
                    ans.push_back(sum);
                }
                else if(sum > high)
                {
                    return ans;
                }
                leftPointer++;
                rightPointer++;
            }

        }
        return ans;
    }
};