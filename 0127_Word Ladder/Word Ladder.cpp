class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dictionary;
        unordered_map<string,int> used;
        int len = wordList.size();
        
        used[beginWord] = -1;

        int wordLen = beginWord.size();

        for(int i = 0; i < len; i++)
        {
            dictionary.insert(wordList[i]);
        }

        queue<string> myQueue;
        myQueue.push(beginWord);

        int step = 1;

        while(myQueue.empty() == false)
        {
            int bound = myQueue.size();
            while(bound > 0)
            {
                string s = myQueue.front();
                myQueue.pop();
                int usedIndex = used[s];
                for(int i = 0; i < wordLen; i++)
                {
                    if(i == usedIndex)
                    {
                        continue;
                    }
                    char original = s[i];
                    for(int j = 0; j < 26; j++)
                    {
                        s[i] = 'a'+j;
                        if(dictionary.find(s) != dictionary.end() && used.find(s) == used.end())
                        {
                            if(s == endWord)
                            {
                                return step+1;
                            }
                            myQueue.push(s);
                            used[s] = i;
                        }
                    }
                    s[i] = original;
                }
                bound--;
            }
            step++;
        }
        return 0;
    }
};