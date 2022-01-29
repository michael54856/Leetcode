class Solution
{
public:
    class node
    {
    public:
        int index;
        int value;
        node(int v, int n)
        {
            value = v;
            index = n;
        }
    };
    int largestRectangleArea(vector<int>& heights)
    {
        int len = heights.size();
        stack<node> myStack;
        myStack.push(node(0,0));
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            while(myStack.top().value > heights[i])
            {
                node temp =  myStack.top();
                myStack.pop();
                ans = max(temp.value*((temp.index-myStack.top().index)+(i-temp.index)), ans);
            }

            myStack.push(node(heights[i],i+1));
        }

        while(myStack.top().value > 0)
        {
            node temp =  myStack.top();
            myStack.pop();
            ans = max(temp.value*((temp.index-myStack.top().index)+(len-temp.index)), ans);
        }

        return ans;
    }
};
