class WordDictionary
 {
public:
    vector<string> *bucket;
    WordDictionary()
    {
        bucket = new vector<string>[5001];
    }

    void addWord(string word)
    {
        int len = word.size();
        bucket[len].push_back(word);
    }

    bool search(string word)
    {
        int len = word.size();
        int bound = bucket[len].size();
        for(int i = 0; i < bound; i++)
        {
            if(sameWord(word,bucket[len][i]))
            {
                return true;
            }
        }
        return false;
    }

    bool sameWord(string s1, string s2)
    {
        int len = s1.size();
        for(int i = 0; i < len; i++)
        {
            if(s1[i] == '.')
            {
                continue;
            }
            else
            {
                if(s1[i] != s2[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};