class Solution
{
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B)
    {
        short dic[26] = {};
        int B_len = B.size();
        for(int i = 0; i < B_len; i++)
        {
            short tempDic[26] = {};
            for(int j = 0; j < B[i].size(); j++)
            {
                tempDic[B[i][j]-'a']++;
            }
            for(int j = 0; j < 26; j++)
            {
                if(tempDic[j] > dic[j])
                {
                    dic[j] = tempDic[j];
                }
            }
        }
        vector<string> ans;
        int len = A.size();
        for(int i = 0; i < len; i++)
        {
            short A_Dic[26] = {};
            for(int j = 0; j < A[i].size(); j++)
            {
                A_Dic[A[i][j]-'a']++;
            }
            bool flag = false;
            for(int j = 0; j < 26; j++)
            {
                if(A_Dic[j] < dic[j])
                {
                    flag = true;
                    break;
                }
            }

            if(flag == false)
            {
                ans.push_back(A[i]);
            }
        }
        return ans;
    }
};