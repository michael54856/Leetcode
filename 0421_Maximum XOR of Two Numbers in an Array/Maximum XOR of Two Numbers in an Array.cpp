class Solution
{
public:
    class node
    {
    public:
        node *left; //代表0
        node *right; //代表1
    };
    int findMaximumXOR(vector<int>& nums)
    {
        node *root = new node(); //進行new的時候裡面的data會做初始化
        int len = nums.size();

        for(int i = 0; i < len; i++) //建構trie
        {
            node *current = root;
            for(int j = 30; j >= 0; j--)
            {
                int t = (nums[i] >> j) & 1;
                if(t == 0)
                {
                    if(current->left == nullptr)
                    {
                        current->left = new node();
                        current = current->left;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if(current->right == nullptr)
                    {
                        current->right = new node();
                        current = current->right;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }

        //先找到數字的最高位
        node *current = root;
        int highest = 31;
        while(current)
        {
            if(current->right)
            {
                break;
            }
            current = current->left;
            highest--;
        }

        if(highest <= 0)//全部的數字都是0
        {
            return 0;
        }

        int ans = 0;

        int bound = (1 << (highest-1));
        

        for(int i = 0; i < len; i++)
        {
            if(nums[i] >= bound)
            {
                node *current = root;
                int val = 0;
                for(int j = 30; j >= 0; j--)
                {
                    int t = (nums[i] >> j) & 1;
                    if(t == 0)
                    {
                        if(current->right == nullptr)//右邊沒東西
                        {
                            current = current->left;
                            val <<= 1;
                        }
                        else
                        {
                            current = current->right;//右邊有東西
                            val <<= 1;
                            val++;
                        }
                    }
                    else
                    {
                        if(current->left == nullptr)//左邊沒東西
                        {
                            current = current->right;
                            val <<= 1;
                            val++;
                        }
                        else
                        {
                            current = current->left;//左邊有東西
                            val <<= 1;
                        }
                    }
                }
                int temp =nums[i] ^ val;
                if(temp > ans)
                {
                    ans = temp;
                }
            }
            

        }
        
        return ans;

    }
};
