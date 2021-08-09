class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();
        int sum;
        int carry = 0;
        if(len1 > len2)
        {
            for(int i = 1; i <= len2; i++)
            {
                sum = num1[len1-i] + num2[len2-i] + carry - 96;
                if(sum >= 10)
                {
                    carry = 1;
                    num1[len1-i] = (char)(sum-10+'0');
                }
                else
                {
                    carry = 0;
                    num1[len1-i] = (char)(sum+'0');
                }
            }

            for(int i = len2+1; i <= len1 && carry == 1; i++)
            {
                if(num1[len1-i]+carry >= 58)//58 = '0'+10
                {
                    num1[len1-i] = (char)(num1[len1-i]+carry-10);
                    carry = 1;
                }
                else
                {
                    num1[len1-i] = (char)(num1[len1-i]+carry);
                    carry = 0;
                }
            }
            if(carry == 1)
            {
                return "1"+num1;
            }
            return num1;
        }
        else
        {
            for(int i = 1; i <= len1; i++)
            {
                sum = num1[len1-i] + num2[len2-i] + carry - 96;
                if(sum >= 10)
                {
                    carry = 1;
                    num2[len2-i] = (char)(sum-10+'0');
                }
                else
                {
                    carry = 0;
                    num2[len2-i] = (char)(sum+'0');
                }
            }
            for(int i = len1+1; i <= len2 && carry == 1; i++)
            {
                if(num2[len2-i]+carry >= 58)//58 = '0'+10
                {
                    num2[len2-i] = (char)(num2[len2-i]+carry-10);
                    carry = 1;
                }
                else
                {
                    num2[len2-i] = (char)(num2[len2-i]+carry);
                    carry = 0;
                }
            }
            if(carry == 1)
            {
                return "1"+num2;
            }
            return num2;
        }
        return "";
    }
};