class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) 
    {
        int a[101] = {};
        int len = logs.size();
        for(int i = 0; i < len; i++)
        {
            a[logs[i][0]-1950]++;
            a[logs[i][1]-1950]--;
        }
        
        int num = 0;
        int year = 1950;
        int ans = 0;
        
        for(int i = 0; i <= 100; i++)
        {
            num += a[i];
            if(num > ans)
            {
                ans = num;
                year=i+1950;
            }
        }
        return year;
        
    }
};