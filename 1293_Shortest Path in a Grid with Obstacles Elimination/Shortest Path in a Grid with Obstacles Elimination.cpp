class Solution {
public:
    struct node
    {
        int x;
        int y;
        int obstacleBreak;
        node(int a, int b, int c)
        {
            y = a;
            x = b;
            obstacleBreak = c;
        }
    };

    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<node> myQueue;

        grid[0][0] = -(k+1);
        myQueue.push(node(0,0,-(k+1)));

        int step = 0;
        bool haveAns = false;

        while(myQueue.empty() == false)
        {
            int t = myQueue.size();
            for(int i = 0; i < t; i++)
            {
                node currentNode = myQueue.front();
                myQueue.pop();

                if(currentNode.y == m-1 && currentNode.x == n-1)
                {
                    haveAns = true;
                    break;
                }
                

                if(currentNode.y-1 >= 0)//up
                {
                    if(grid[currentNode.y-1][currentNode.x] == 0)
                    {
                        grid[currentNode.y-1][currentNode.x] = currentNode.obstacleBreak;
                        myQueue.push(node(currentNode.y-1,currentNode.x,currentNode.obstacleBreak));
                    }
                    else if(grid[currentNode.y-1][currentNode.x] == 1)
                    {
                        if(currentNode.obstacleBreak < -1)
                        {
                            grid[currentNode.y-1][currentNode.x] = currentNode.obstacleBreak-9999;
                            myQueue.push(node(currentNode.y-1,currentNode.x,currentNode.obstacleBreak+1));
                        }
                    }
                    else//have walked
                    {
                        if(grid[currentNode.y-1][currentNode.x] < -10000)//haveObstacle
                        {
                            if(currentNode.obstacleBreak < -1)
                            {
                                if(currentNode.obstacleBreak-9999 < grid[currentNode.y-1][currentNode.x])
                                {
                                    grid[currentNode.y-1][currentNode.x] = currentNode.obstacleBreak-9999;
                                    myQueue.push(node(currentNode.y-1,currentNode.x,currentNode.obstacleBreak+1));
                                }
                            }
                        }
                        else
                        {
                            if(currentNode.obstacleBreak < grid[currentNode.y-1][currentNode.x])//compare if it has more obstacle break times
                            {
                                grid[currentNode.y-1][currentNode.x] = currentNode.obstacleBreak;
                                myQueue.push(node(currentNode.y-1,currentNode.x,currentNode.obstacleBreak));
                            }
                        }

                    }
                }
                if(currentNode.y+1 < m)//down
                {
                    if(grid[currentNode.y+1][currentNode.x] == 0)
                    {
                        grid[currentNode.y+1][currentNode.x] = currentNode.obstacleBreak;
                        myQueue.push(node(currentNode.y+1,currentNode.x,currentNode.obstacleBreak));
                    }
                    else if(grid[currentNode.y+1][currentNode.x] == 1)
                    {
                        if(currentNode.obstacleBreak < -1)
                        {
                            grid[currentNode.y+1][currentNode.x] = currentNode.obstacleBreak-9999;
                            myQueue.push(node(currentNode.y+1,currentNode.x,currentNode.obstacleBreak+1));
                        }
                    }
                    else//have walked
                    {
                        if(grid[currentNode.y+1][currentNode.x] < -10000)//haveObstacle
                        {
                            if(currentNode.obstacleBreak < -1)
                            {
                                if(currentNode.obstacleBreak-9999 < grid[currentNode.y+1][currentNode.x])
                                {
                                    grid[currentNode.y+1][currentNode.x] = currentNode.obstacleBreak-9999;
                                    myQueue.push(node(currentNode.y+1,currentNode.x,currentNode.obstacleBreak+1));
                                }
                            }
                        }
                        else
                        {
                            if(currentNode.obstacleBreak < grid[currentNode.y+1][currentNode.x])//compare if it has more obstacle break times
                            {
                                grid[currentNode.y+1][currentNode.x] = currentNode.obstacleBreak;
                                myQueue.push(node(currentNode.y+1,currentNode.x,currentNode.obstacleBreak));
                            }
                        }

                    }
                }

                if(currentNode.x-1 >= 0)//left
                {
                     if(grid[currentNode.y][currentNode.x-1] == 0)
                    {
                        grid[currentNode.y][currentNode.x-1] = currentNode.obstacleBreak;
                        myQueue.push(node(currentNode.y,currentNode.x-1,currentNode.obstacleBreak));
                    }
                    else if(grid[currentNode.y][currentNode.x-1] == 1)
                    {
                        if(currentNode.obstacleBreak < -1)
                        {
                            grid[currentNode.y][currentNode.x-1] = currentNode.obstacleBreak-9999;
                            myQueue.push(node(currentNode.y,currentNode.x-1,currentNode.obstacleBreak+1));
                        }
                    }
                    else//have walked
                    {
                        if(grid[currentNode.y][currentNode.x-1] < -10000)//haveObstacle
                        {
                            if(currentNode.obstacleBreak < -1)
                            {
                                if(currentNode.obstacleBreak-9999 < grid[currentNode.y][currentNode.x-1])
                                {
                                    grid[currentNode.y][currentNode.x-1] = currentNode.obstacleBreak-9999;
                                    myQueue.push(node(currentNode.y,currentNode.x-1,currentNode.obstacleBreak+1));
                                }
                            }
                        }
                        else
                        {
                            if(currentNode.obstacleBreak < grid[currentNode.y][currentNode.x-1])//compare if it has more obstacle break times
                            {
                                grid[currentNode.y][currentNode.x-1] = currentNode.obstacleBreak;
                                myQueue.push(node(currentNode.y,currentNode.x-1,currentNode.obstacleBreak));
                            }
                        }

                    }
                }

                if(currentNode.x+1 < n)//right
                {
                    if(grid[currentNode.y][currentNode.x+1] == 0)
                    {
                        grid[currentNode.y][currentNode.x+1] = currentNode.obstacleBreak;
                        myQueue.push(node(currentNode.y,currentNode.x+1,currentNode.obstacleBreak));
                    }
                    else if(grid[currentNode.y][currentNode.x+1] == 1)
                    {
                        if(currentNode.obstacleBreak < -1)
                        {
                            grid[currentNode.y][currentNode.x+1] = currentNode.obstacleBreak-9999;
                            myQueue.push(node(currentNode.y,currentNode.x+1,currentNode.obstacleBreak+1));
                        }
                    }
                    else//have walked
                    {
                        if(grid[currentNode.y][currentNode.x+1] < -10000)//haveObstacle
                        {
                            if(currentNode.obstacleBreak < -1)
                            {
                                if(currentNode.obstacleBreak-9999 < grid[currentNode.y][currentNode.x+1])
                                {
                                    grid[currentNode.y][currentNode.x+1] = currentNode.obstacleBreak-9999;
                                    myQueue.push(node(currentNode.y,currentNode.x+1,currentNode.obstacleBreak+1));
                                }
                            }
                        }
                        else
                        {
                            if(currentNode.obstacleBreak < grid[currentNode.y][currentNode.x+1])//compare if it has more obstacle break times
                            {
                                grid[currentNode.y][currentNode.x+1] = currentNode.obstacleBreak;
                                myQueue.push(node(currentNode.y,currentNode.x+1,currentNode.obstacleBreak));
                            }
                        }

                    }
                }

            }
            if(haveAns == true)
            {
                break;
            }
            step++;
        }

        if(haveAns == true)
        {
            return step;
        }
        return -1;

    }
};