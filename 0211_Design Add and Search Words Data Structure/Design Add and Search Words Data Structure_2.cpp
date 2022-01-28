class WordDictionary
{
public:

    class node
    {
    public:
        node *next[26];
    };

    node **trieArr;
    WordDictionary()
    {
        trieArr = new node*[5001]();
    }

    void addWord(string word)
    {
        int len = word.size();
        if(trieArr[len] == nullptr)
        {
            trieArr[len] = new node();
        }
        node* current = trieArr[len];
        for(int i = 0; i < len; i++)
        {
            int index = word[i]-'a';
            if(current->next[index] == nullptr)
            {
                current->next[index] = new node();
            }
            current = current->next[index];
        }
    }

    bool search(string s)
    {
        int len = s.size();
        node *current = trieArr[len];
        if(trieArr[len] == nullptr)
        {
            return false;
        }
        return dfsSearch(s,0,len,current);
    }

    bool dfsSearch(string &s, int pos, int &len, node *current)
    {
        if(pos == len)
        {
            return true;
        }
        if(s[pos] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(current->next[i])
                {
                    bool t = dfsSearch(s,pos+1,len,current->next[i]);
                    if(t == true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        else
        {
            if(current->next[s[pos]-'a'])
            {
                return dfsSearch(s,pos+1,len,current->next[s[pos]-'a']);
            }
            return false;
        }
    }
};