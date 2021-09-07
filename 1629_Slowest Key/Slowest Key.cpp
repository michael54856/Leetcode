class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        int len = keysPressed.size();
        
        char ans = keysPressed[0];
        int maxVal = releaseTimes[0];
        
        for(int i = 1; i < len; i++)
        {
            int t = releaseTimes[i] - releaseTimes[i-1];
            if(t > maxVal)
            {
                ans = keysPressed[i];
                maxVal = t;
            }
            else if(t == maxVal && keysPressed[i] > ans)
            {
                ans = keysPressed[i];
            }
            
        }
        return ans;
    }
};