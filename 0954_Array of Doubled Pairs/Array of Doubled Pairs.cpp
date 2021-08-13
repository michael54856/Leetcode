class Solution
{
public:
    bool canReorderDoubled(vector<int>& arr)
    {
        int len = arr.size();
        int *appear = new int[200001]();
        int positiveArr[30000];
        int negativeArr[30000];
        int posNum = 0;
        int negNum = 0;
        for(int i = 0; i < len; i++)
        {
            appear[arr[i]+100000]++;
            if(arr[i] > 50000 || arr[i] < -50000)
            {
                return false;
            }
            if(arr[i] > 0)
            {
                positiveArr[posNum] = arr[i];
                posNum++;
            }
            else
            {
                negativeArr[negNum] = arr[i];
                negNum++;
            }
        }
        if(appear[0] % 2 != 0 || posNum % 2 == 1 || negNum % 2 == 1)
        {
            return false;
        }

        sort(positiveArr,positiveArr+posNum);
        for(int i = 0; i < posNum; i++)
        {
            if(appear[positiveArr[i]+100000] > 0)
            {
                int doubleNum = positiveArr[i] << 1;//arr[i] * 2
                if(appear[doubleNum+100000] > 0)
                {
                    appear[positiveArr[i]+100000]--;
                    appear[doubleNum+100000]--;
                }
                else
                {
                    return false;
                }
            }
        }

        sort(negativeArr,negativeArr+negNum);
        for(int i = 0; i < negNum; i++)
        {
            if(appear[negativeArr[i]+100000] > 0)
            {
                int doubleNum = negativeArr[i] >> 1;//arr[i] * 2
                if(appear[doubleNum+100000] > 0)
                {
                    appear[negativeArr[i]+100000]--;
                    appear[doubleNum+100000]--;
                }
                else
                {
                    return false;
                }
            }

        }
        return true;
    }
};