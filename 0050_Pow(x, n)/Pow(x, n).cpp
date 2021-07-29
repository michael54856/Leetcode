class Solution {
public:
    double myPow(double x, int n)
    {
        if(n == 0)
        {
            return 1;
        }

        if(n < 0)
        {
            if(n%2 == -1)
            {
                double half = myPow(x,n/2);
                return half*half*(1.0/x);
            }
            else
            {
                 double half = myPow(x,n/2);
                return half*half;
            }
        }
        else
        {
            if(n%2 == 1)
            {
                double half = myPow(x,n/2);
                return half*half* x;
            }
            else
            {
                double half = myPow(x,n/2);
                return half*half;
            }
        }
    }
};