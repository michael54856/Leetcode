class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        bool **graph = new bool*[n];
        int **leftSumMatrix = new int*[n];
        int **rightSumMatrix = new int*[n];
        int **topSumMatrix = new int*[n];
        int **bottomSumMatrix = new int*[n];

        for(int i = 0; i < n; i++)
        {
            leftSumMatrix[i] = new int[n];
            rightSumMatrix[i] = new int[n];
            topSumMatrix[i] = new int[n];
            bottomSumMatrix[i] = new int[n];
            graph[i] = new bool[n]();
        }

        int len = mines.size();
        for(int i = 0; i < len; i++)
        {
            graph[mines[i][0]][mines[i][1]] = true;
        }


        for(int i = 0; i < n; i++)//left to right
        {
            int leftSum = 0;
            int rightSum = 0;
            int topSum = 0;
            int bottomSum = 0;
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] == true)//left-right
                {
                    leftSum = 0;
                    leftSumMatrix[i][j] = leftSum;
                }
                else
                {
                    leftSum++;
                    leftSumMatrix[i][j] = leftSum;
                }

                if(graph[i][n-1-j] == true)//right-left
                {
                    rightSum = 0;
                    rightSumMatrix[i][n-1-j] = rightSum;
                }
                else
                {
                    rightSum++;
                    rightSumMatrix[i][n-1-j] = rightSum;
                }

                if(graph[j][i] == true)//top-down
                {
                    topSum = 0;
                    topSumMatrix[j][i] = topSum;
                }
                else
                {
                    topSum++;
                    topSumMatrix[j][i] = topSum;
                }

                if(graph[n-1-j][i] == true)//bottom-up
                {
                    bottomSum = 0;
                    bottomSumMatrix[n-1-j][i] = bottomSum;
                }
                else
                {
                    bottomSum++;
                    bottomSumMatrix[n-1-j][i] = bottomSum;
                }
            }
        }
        

        int ans = 0;
        
        for(int i = 0; i < n; i++)//corner edge
        {
            if(graph[0][i] == false)// top
            {
                ans = 1;
            }
            if(graph[n-1][i] == false)//bottom
            {
                ans = 1;
            }
            if(graph[i][0] == false)//left
            {
                ans = 1;
            }
            if(graph[i][n-1] == false)//right
            {
                ans = 1;
            }
        }
        

        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < n-1; j++)
            {
                if(graph[i][j] == false)
                {
                    int temp = min(topSumMatrix[i][j], rightSumMatrix[i][j]);
                    temp = min(temp, bottomSumMatrix[i][j]);
                    temp = min(temp, leftSumMatrix[i][j]);

                    ans = max(ans,temp);
                }
            }
        }
        
        
        
        return ans;

    }
};