class Solution
{
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        int len = arr.size();
        if(len == 1)
        {
            return 1;
        }
        if(len == 2)
        {
            if(arr[0] == arr[1])
            {
                return 1;
            }
            return 2;
        }

        int ans = 1;
        int counter = 0;
        int pos;

        bool flag;//true:> , false:<

        for(int i = 0; i < len-1; i++)//find first not equal
        {
            if(arr[i] != arr[i+1])
            {
                if(arr[i] > arr[i+1])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                counter = 2;
                pos = i+1;
                break;
            }
        }

        for(int i = pos; i < len-1; i++)
        {
            if(flag == true)
            {
                if(arr[i] < arr[i+1])
                {
                    flag = !flag;
                    counter++;
                }
                else
                {
                    if(counter > ans)
                    {
                        ans = counter;
                    }
                    for( ; i < len-1; i++)
                    {
                        if(arr[i] != arr[i+1])
                        {
                            if(arr[i] > arr[i+1])
                            {
                                flag = true;
                            }
                            else
                            {
                                flag = false;
                            }
                            counter = 2;
                            pos = i+1;
                            break;
                        }
                    }
                }
            }
            else
            {
                if(arr[i] > arr[i+1])
                {
                    flag = !flag;
                    counter++;
                }
                else
                {
                    if(counter > ans)
                    {
                        ans = counter;
                    }
                    for( ; i < len-1; i++)
                    {
                        if(arr[i] != arr[i+1])
                        {
                            if(arr[i] > arr[i+1])
                            {
                                flag = true;
                            }
                            else
                            {
                                flag = false;
                            }
                            counter = 2;
                            pos = i+1;
                            break;
                        }
                    }
                }
            }
        }

        if(counter > ans)
        {
            ans = counter;
        }

        return ans;

    }
};