class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        int len = palindrome.size();
        if(len == 1)
        {
            return "";
        }
        int mid = len/2;
        for(int i = 0; i < mid; i++)//scan from left , find the first character that isn't a
        {
            if(palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[len-1] = 'b';
        return palindrome;
    }
};