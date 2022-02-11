class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();

        int left = 0;

        int dic1[26] = {};
        int dic2[26] = {};

        for(int i = 0; i < len1; i++)
        {
            dic1[s1[i]-'a']++;
        }

        for(int i = 0; i < len2; i++)
        {
            if(dic1[s2[i]-'a'] == 0)
            {
                for(int j = 0; j < 26; j++)
                {
                    dic2[j] = 0;
                }
                left = i+1;
            }
            else
            {
                dic2[s2[i]-'a']++;

                if(dic2[s2[i]-'a'] == dic1[s2[i]-'a'])
                {
                    bool allSame = true;
                    for(int j = 0; j < 26; j++)
                    {
                        if(dic2[j] != dic1[j])
                        {
                            allSame = false;
                            break;
                        }
                    }
                    if(allSame == true)
                    {
                        return true;
                    }
                }
                else if(dic2[s2[i]-'a'] > dic1[s2[i]-'a'])
                {
                    while(s2[left] != s2[i])
                    {
                        dic2[s2[left]-'a']--;
                        left++;
                    }
                    left++;
                    dic2[s2[i]-'a']--;
                }
            }

        }
        return false;

    }
};