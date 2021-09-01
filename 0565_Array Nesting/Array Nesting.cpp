class Solution {
public:
    int arrayNesting(vector<int>& nums) 
    {
        int len = nums.size();
        int ans = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != -1)
            {
                int start = i;
                int t = nums[i];//指向下一個
                nums[i] = -1;
                int counter = 1;
                
                int temp;
                while(t != start)
                {
                    temp = t;
                    t = nums[temp];
                    nums[temp] = -1;
                    counter++;
                }
                if(counter > ans)
                {
                    ans = counter;
                }
            }
        }
        return ans;
        
    }
};