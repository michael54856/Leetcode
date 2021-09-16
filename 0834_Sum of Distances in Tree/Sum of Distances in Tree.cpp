class Solution
{
public:

    struct node
    {
        node(int a, node* ne)
        {
            nodeVal = a;
            next = ne;
        }
        int nodeVal;
        node* next;//adjList
    };

    bool *hasPassed;
    node** nodeList;

    int *nodeCountBelow;
    int *pathCountBelow;

    void dfs(int currentNode)//construct nodeCountBelow & pathCountBelow
    {
        node *current = nodeList[currentNode];
        int totalPathBelow = 0;
        int totalNodeBelow = 1;

        while(current != nullptr)
        {
            if(hasPassed[current->nodeVal] == false)
            {
                hasPassed[current->nodeVal] = true;

                dfs(current->nodeVal);

                totalNodeBelow += nodeCountBelow[current->nodeVal];
                totalPathBelow += pathCountBelow[current->nodeVal] + nodeCountBelow[current->nodeVal];
            }
            current = current->next;
        }

        nodeCountBelow[currentNode] = totalNodeBelow;
        pathCountBelow[currentNode] = totalPathBelow;
    }

    void dfs_2(int currentNode, int nodeCount, int pathCount, vector<int> &ans)
    {
        node *current = nodeList[currentNode];

        ans[currentNode] = pathCount + pathCountBelow[currentNode];//up + down

        while(current != nullptr)
        {
            if(hasPassed[current->nodeVal] == true)
            {
                hasPassed[current->nodeVal] = false;

                dfs_2(current->nodeVal, nodeCount+nodeCountBelow[currentNode]-nodeCountBelow[current->nodeVal], (pathCountBelow[currentNode]-(pathCountBelow[current->nodeVal]+nodeCountBelow[current->nodeVal]))+pathCount+(nodeCount+nodeCountBelow[currentNode]-nodeCountBelow[current->nodeVal]), ans);

            }
            current = current->next;
        }

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<int> ans(n);

        int len = edges.size();
        hasPassed = new bool[n]();
        nodeList = new node*[n]();
        nodeCountBelow = new int[n]();
        pathCountBelow = new int[n]();

        for(int i = 0,a,b; i < len; i++)
        {
            a = edges[i][0];
            b = edges[i][1];

            nodeList[a] = new node(b,nodeList[a]);
            nodeList[b] = new node(a,nodeList[b]);
        }

        hasPassed[0] = true;
        dfs(0);

        hasPassed[0] = false;
        dfs_2(0,0,0,ans);


        return ans;

    }

};