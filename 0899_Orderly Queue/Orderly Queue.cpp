class Solution {
public:
    string orderlyQueue(string s, int k)
    {
        if(k >= 2)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            int len = s.size();
            string ans = s;
            string rotateS = ans;
            for(int i = 1; i < len; i++)
            {
                char c = rotateS[0];
                rotateS = rotateS.substr(1);
                rotateS += c;
                if(rotateS < ans)
                {
                    ans = rotateS;
                }
            }
            return ans;
        }
    }
};