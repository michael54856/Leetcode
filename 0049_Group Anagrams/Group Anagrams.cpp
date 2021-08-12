class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string,vector<string>> myMap;
        map<string,vector<string>>::iterator iter;
        int len = strs.size();
        for(int i = 0; i < len; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            iter = myMap.find(s);
            if(iter == myMap.end())
            {
                vector<string> temp;
                temp.push_back(strs[i]);
                myMap[s] = temp;
            }
            else
            {
                (iter->second).push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            ans.push_back(iter->second);
        }
        return ans;
    }
};