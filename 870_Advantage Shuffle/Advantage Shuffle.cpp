class Solution
{
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
         multiset<int> mySet(A.begin(), A.end());
         vector<int> ans;
         int len = B.size();
         multiset<int>::iterator iter;
         for(int i = 0; i < len; i++)
         {
             iter = mySet.upper_bound(B[i]);
             if(iter == mySet.end())//沒有比他大的,填入最小的
             {
                 iter = mySet.begin();
             }
             ans.push_back(*iter);
             mySet.erase(iter);
         }
         return ans;
    }
};