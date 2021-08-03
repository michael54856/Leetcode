class Solution
{
public:
    struct node
    {
        node(int a, int b) : y{a}, x{b}
        {
        }
        int y;
        int x;
    };
    queue<node> q;
    int len;
    int islandList[100000] = {};
    int islandCount = 2;
    int maxIsland = 0;

    void visitIsalnd(vector<vector<int>>& grid, int i, int j)//BFS
    {
        grid[i][j] = islandCount;
        q.push(node(i,j));
        while(q.empty() == false)
        {
            node currentNode = q.front();
            q.pop();
            islandList[islandCount]++;

            if(currentNode.y-1 >=0 && grid[currentNode.y-1][currentNode.x] == 1)//up
            {
                q.push(node(currentNode.y-1,currentNode.x));
                grid[currentNode.y-1][currentNode.x] = islandCount;
            }
            if(currentNode.y+1 < len && grid[currentNode.y+1][currentNode.x] == 1)//down
            {
                q.push(node(currentNode.y+1,currentNode.x));
                grid[currentNode.y+1][currentNode.x] = islandCount;
            }
            if(currentNode.x-1 >=0 && grid[currentNode.y][currentNode.x-1] == 1)//left
            {
                q.push(node(currentNode.y,currentNode.x-1));
                grid[currentNode.y][currentNode.x-1] = islandCount;
            }
            if(currentNode.x+1 < len && grid[currentNode.y][currentNode.x+1] == 1)//left
            {
                q.push(node(currentNode.y,currentNode.x+1));
                grid[currentNode.y][currentNode.x+1] = islandCount;
            }
        }
        if(islandList[islandCount] > maxIsland)
        {
            maxIsland = islandList[islandCount];
        }
        islandCount++;
    }
    int largestIsland(vector<vector<int>>& grid)
    {
        len = grid.size();
        int ans = 0;

        int visitedIsland[4];
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                if(grid[i][j] == 1)//not visited this island before
                {
                    visitIsalnd(grid,i,j);
                }
                else if(grid[i][j] == 0)
                {
                    int total = 1;
                    int x = 0;
                    if(i-1 >= 0)//up exist
                    {
                        if(grid[i-1][j] == 1)//doesn't visit before
                        {
                            visitIsalnd(grid,i-1,j);
                        }
                        if(grid[i-1][j] > 1)
                        {
                            total += islandList[grid[i-1][j]];
                            visitedIsland[x] = grid[i-1][j];
                            x++;
                        }
                    }
                    if(i+1 < len)//down exist
                    {
                        if(grid[i+1][j] == 1)//doesn't visit before
                        {
                            visitIsalnd(grid,i+1,j);
                        }
                        if(grid[i+1][j] > 1)
                        {
                            bool isConnected = false;
                            for(int k = 0; k < x; k++)
                            {
                                if(visitedIsland[k] == grid[i+1][j])
                                {
                                    isConnected = true;
                                    break;
                                }
                            }
                            if(isConnected == false)
                            {
                                total += islandList[grid[i+1][j]];
                                visitedIsland[x] = grid[i+1][j];
                                x++;
                            }
                        }
                    }
                    if(j+1 < len)//right exist
                    {
                        if(grid[i][j+1] == 1)//doesn't visit before
                        {
                           visitIsalnd(grid,i,j+1);
                        }
                        if(grid[i][j+1] > 1)
                        {
                            bool isConnected = false;
                            for(int k = 0; k < x; k++)
                            {
                                if(visitedIsland[k] == grid[i][j+1])
                                {
                                    isConnected = true;
                                    break;
                                }
                            }
                            if(isConnected == false)
                            {
                                total += islandList[grid[i][j+1]];
                                visitedIsland[x] = grid[i][j+1];
                                x++;
                            }
                        }
                    }
                    if(j-1 >= 0)//left exist
                    {
                        if(grid[i][j-1] == 1)//doesn't visit before
                        {
                            visitIsalnd(grid,i,j-1);
                        }
                        if(grid[i][j-1] > 1)
                        {
                            bool isConnected = false;
                            for(int k = 0; k < x; k++)
                            {
                                if(visitedIsland[k] == grid[i][j-1])
                                {
                                    isConnected = true;
                                    break;
                                }
                            }
                            if(isConnected == false)
                            {
                                total += islandList[grid[i][j-1]];
                                visitedIsland[x] = grid[i][j-1];
                                x++;
                            }
                        }
                    }
                    if(total > ans)
                    {
                        ans = total;
                    }
                }

            }
        }

        return max(ans,maxIsland);

    }
};