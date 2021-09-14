class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int len = s.size();

        int l = 0;
        int r = len-1;

        while(l < len)
        {
            if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))//is letter
            {
                break;
            }
            l++;
        }

        while(r >= 0)
        {
            if((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z'))//is letter
            {
                break;
            }
            r--;
        }

        while(l < r)
        {
            swap(s[l],s[r]);
            l++;
            r--;

            while(l < len)
            {
                if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))//is letter
                {
                    break;
                }
                l++;
            }



            while(r >= 0)
            {
                if((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z'))//is letter
                {
                    break;
                }
                r--;
            }

        }

        return s;

    }
};