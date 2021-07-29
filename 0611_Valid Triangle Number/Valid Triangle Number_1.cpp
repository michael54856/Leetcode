class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        //counting sort
        short a[1001] = {};
        int len = nums.size();
        int max_ = -1;
        for(int i = 0; i < len; i++)
        {
            a[nums[i]]++;
            if(nums[i] > max_)
            {
                max_ = nums[i];
            }
        }
        short sortedNum[1001];
        int x = 0;


        for(int i = 1; i <= max_; i++)
        {
            if(a[i] != 0)
            {
                sortedNum[x] = i;
                x++;
            }
        }

        int ans = 0;
        for(int i = 0; i < x; i++)
        {
            int t = a[sortedNum[i]];//t = sortedNum[i]的個數
            if(t >= 3)
            {
                ans += t*(t-1)*(t-2)/6;
            }
            if(t >= 2)
            {
                int comb_2 = (t*(t-1)) >> 1;//C t取2的組合數
                for(int j = i+1; j < x; j++)
                {
                    if(sortedNum[j] >= (sortedNum[i]<<1))
                    {
                        break;
                    }
                    ans += comb_2*a[sortedNum[j]];
                }
            }
            for(int j = i+1; j < x; j++)
            {
                int y = a[sortedNum[j]];//y = sortedNum[j]的個數
                if(a[sortedNum[j]] >= 2)
                {
                    ans += t*((y*(y-1))>>1);
                }
                for(int k = j+1; k < x; k++)
                {
                    if(sortedNum[k] >= (sortedNum[i]+sortedNum[j]))
                    {
                        break;
                    }
                    ans += t*y*a[sortedNum[k]];

                }

            }
        }
        return ans;


    }
};
