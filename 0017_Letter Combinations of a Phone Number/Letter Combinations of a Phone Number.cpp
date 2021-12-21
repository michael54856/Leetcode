class Solution {
public:
    int len;
    int lenCount[8] = {3,3,3,3,3,4,3,4};
    string dic[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits)
    {
        len = digits.size();
        if(len == 0)
        {
            return ans;
        }
        string s = "";
        DFS(digits,s,0);
        return ans;
    }

    void DFS(string &digits, string &s,int pos)
    {
        if(pos == len)
        {
            ans.push_back(s);
            return;
        }
        int index = digits[pos]-'2';
        for(int i = 0; i < lenCount[index]; i++)
        {
            s += dic[index][i];
            DFS(digits,s,pos+1);
            s.pop_back();

        }
    }
};