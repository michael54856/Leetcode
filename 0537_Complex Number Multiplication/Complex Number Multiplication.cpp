class Solution {
public:

    int myAtoi(string &s)
    {
        int total = 0;
        int len = s.size();
        if(s[0] == '-')
        {
            int mul = 1;
            for(int i = len-1; i > 0; i--)
            {
                total += mul*(s[i]-'0');
                mul *= 10;
            }
            return total * -1;
        }
        else
        {
            int mul = 1;
            for(int i = len-1; i >= 0; i--)
            {
                total += mul*(s[i]-'0');
                mul *= 10;
            }
            return total;
        }
    }
    string toString(int &n)
    {
        if(n == 0)
        {
            return "0";
        }
        string s = "";
        bool isNegative = false;
        if(n < 0)
        {
            isNegative = true;
            n *= -1;
        }
        while(n > 0)
        {
            s += (char)((n%10)+'0');
            n /= 10;
        }
        if(isNegative == true)
        {
            s += '-';
        }
        reverse(s.begin(),s.end());
        return s;
    }

    string complexNumberMultiply(string num1, string num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();
        string num1_real = "";
        string num1_imag = "";

        string num2_real = "";
        string num2_imag = "";

        int pos;
        for(int i = 0; true; i++)
        {
            if(num1[i] == '+')
            {
                pos = i;
                break;
            }
             num1_real += num1[i];
        }
        for(int i = pos+1; i < len1-1; i++)
        {
            num1_imag += num1[i];
        }

        for(int i = 0; true; i++)
        {
            if(num2[i] == '+')
            {
                pos = i;
                break;
            }
             num2_real += num2[i];
        }
        for(int i = pos+1; i < len2-1; i++)
        {
            num2_imag += num2[i];
        }

        int a = myAtoi(num1_real);
        int b = myAtoi(num1_imag);
        int c = myAtoi(num2_real);
        int d = myAtoi(num2_imag);

        int ans1 = a*c - b*d;
        int ans2 = a*d + b*c;

        return toString(ans1) + "+" + toString(ans2) + "i";
    }
};