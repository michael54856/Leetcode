int orderInfo[26] = {};
bool cmp(char a, char b)
{
    return (orderInfo[a-'a'] < orderInfo[b-'a']);
}

class Solution {
public:

    string customSortString(string order, string str)
    {
        int orderLen = order.size();

        for(int i = 0; i < orderLen; i++)
        {
            orderInfo[order[i]-'a'] = i+1;
        }
        string dontNeedSort = "";
        string needSort = "";

        int len = str.size();
        for(int i = 0; i < len; i++)
        {
            if(orderInfo[str[i]-'a'] != 0)
            {
                needSort += str[i];
            }
            else
            {
                dontNeedSort += str[i];
            }
        }
        sort(needSort.begin(), needSort.end(), cmp);
        return (dontNeedSort + needSort);
    }
};