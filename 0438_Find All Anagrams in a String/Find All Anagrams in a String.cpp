class Solution
{
public:
    void initalizeArray(int counter[])
    {
        for(int i = 0; i < 26; i++)
        {
            counter[i] = 0;
        }
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int len1 = s.size();
        int len2 = p.size();
        int dictionary[26] = {};
        int counter[26] = {};
        bool counterEmpty = true;
        int startPos = 0;
        for(int i = 0; i < len2; i++)
        {
            dictionary[p[i]-'a']++;
        }
        for(int i = 0; i < len1; i++)
        {
            int index = s[i]-'a';

            if(dictionary[index] == 0)//沒出現過
            {
                if(counterEmpty == false)//直接更新windows
                {
                    initalizeArray(counter);
                    counterEmpty = true;
                }
                startPos = i+1;
            }
            else
            {
                counter[index]++;
                counterEmpty = false;

                if(counter[index] > dictionary[index])//收縮window
                {
                    while(true)
                    {
                        counter[s[startPos]-'a']--;
                        if(s[startPos]-'a' == index)//遇到第一個則跳掉
                        {
                            startPos++;
                            break;
                        }
                        startPos++;
                    }
                }
                else if(counter[index] == dictionary[index])//判斷看看
                {
                    bool allSame = true;
                    for(int j = 0; j < 26; j++)
                    {
                        if(counter[j] != dictionary[j])
                        {
                            allSame = false;
                            break;
                        }
                    }

                    if(allSame == true)
                    {
                        ans.push_back(startPos);
                        //收縮一格
                        counter[s[startPos]-'a']--;
                        startPos++;
                    }
                }
            }
        }
        return ans;

    }
};