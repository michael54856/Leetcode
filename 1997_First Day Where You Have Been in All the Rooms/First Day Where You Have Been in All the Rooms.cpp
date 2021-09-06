class Solution
{
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit)
    {
        int len = nextVisit.size();
        int *visitCost = new int[len]();//從0開始到下一格的cost

        visitCost[0] = 2;

        for(int i = 1; i < len-1; i++)
        {
            int j = nextVisit[i];
            if(j == i)//指向自己
            {
                visitCost[i] = (2+visitCost[i-1])%1000000007;
            }
            else if(j == 0)
            {
                visitCost[i] = (2 + 2*visitCost[i-1]) % 1000000007;
            }
            else
            {
                long long int t = (2 + 2*((long long int)visitCost[i-1]) - ((long long int)visitCost[j-1]) + 1000000007) % 1000000007;
                visitCost[i] = (int)t;

            }

        }

        return visitCost[len-2];


    }
};