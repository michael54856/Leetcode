class Solution
{
public:
    //leftParenthesisInString = string中還沒被配對的
    //leftParenthesisCount = 不管有沒有配對,在string中的數量
    vector<string> ans;
    void findCombination(string s, int n, int currentLength, int leftParenthesisInString, int leftParenthesisCount)
    {
        if(currentLength == (n << 1))
        {
            ans.push_back(s);
            return;
        }

        if(leftParenthesisInString == 0)
        {
            findCombination(s+'(',n,currentLength+1,1,leftParenthesisCount+1);
        }
        else
        {
            if(leftParenthesisCount == n)//can't add (
            {
                findCombination(s+')',n,currentLength+1,leftParenthesisInString-1,leftParenthesisCount);
            }
            else
            {
                findCombination(s+'(',n,currentLength+1,leftParenthesisInString+1,leftParenthesisCount+1);
                findCombination(s+')',n,currentLength+1,leftParenthesisInString-1,leftParenthesisCount);
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s = "(";
        findCombination(s,n,1,1,1);
        return ans;
    }
};