class Solution {
public:
    string ITOA(int n)
    {
        if(n == 0)
        {
            return "0";
        }
        if(n > 0)
        {
            string s = "";
            while(n > 0)
            {
                s += '0'+(n%10);
                n /= 10;
            }
            reverse(s.begin(), s.end());
            return s;
        }
        else
        {
            string s = "";
            while(n < 0)
            {
                s += '0'+((n%10)*-1);
                n /= 10;
            }
            s += '-';
            reverse(s.begin(), s.end());
            return s;
        }
        
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int len = nums.size();
        if(len == 0)
        {
            return ans;
        }
        int start = nums[0];
        int last = nums[0];
        for(int i = 1; i < len; i++)
        {
            if(nums[i] != last+1)
            {
                if(last == start)
                {
                    ans.push_back(ITOA(last));
                }
                else
                {
                    string temp = "";
                    temp += ITOA(start);
                    temp += "->";
                    temp += ITOA(last);
                    ans.push_back(temp);
                }
                last = nums[i];
                start = nums[i];
            }
            else
            {
                last = nums[i];
            }
        }
        if(last == start)
        {
            ans.push_back(ITOA(last));
        }
        else
        {
            string temp = "";
            temp += ITOA(start);
            temp += "->";
            temp += ITOA(last);
            ans.push_back(temp);
        }
        return ans;
    }
};