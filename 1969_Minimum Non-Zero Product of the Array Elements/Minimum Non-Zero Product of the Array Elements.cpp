class Solution
{
public:
    long long int powerModule(long long int x, long long int n)
    {
        if(n == 1)
        {
            return x % 1000000007;
        }

        if(n & 1)////exponent is odd x^42
        {
            return ((x % 1000000007) * powerModule(x,n-1)) % 1000000007;
        }
        else
        {
            long long int temp = powerModule(x,n/2);
            temp = (temp*temp) % 1000000007;
            return temp;
        }

    }
    int minNonZeroProduct(int p)
    {
        if(p == 1)
        {
            return 1;
        }

        long long int ans;
        long long time;
        for(int i = 0; i < p; i++)
        {
            time *= 2;
        }
        ans = time-1;
        ans %= 1000000007;//the last number to multiply

        long long int x = time-2;
        long long int n = x/2;
        x %= 1000000007;  //(x*x*x......) % 1000000007 = (x%1000000007)*(x%1000000007)*...
        long long int result = powerModule(x,n);//result = (x^n)%1000000007

        ans *= result;
        ans %= 1000000007;

        return ans;
    }
};