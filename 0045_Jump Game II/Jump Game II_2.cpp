class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 1)
        {
            return 0;
        }

        int start_ = 0;
        int end_ = 0;

        int steps = 0;

        while(true)
        {
            steps++;
            int nextStart = end_+1;
            int nextEnd = end_;
            for(int i = start_; i <= end_; i++)
            {
                int t = i+nums[i];
                if(t >= len-1)
                {
                    return steps;
                }
                if(i+nums[i] > nextEnd)
                {
                    nextEnd = i+nums[i];
                }
            }
            start_ = nextStart;
            end_ = nextEnd;
        }
        return 0;

    }
};