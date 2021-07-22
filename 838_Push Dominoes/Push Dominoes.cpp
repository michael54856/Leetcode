class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int len = dominoes.size();

        bool falling = false;
        int indexCount = 0;

        for(int i = 0; i < len; i++)//先處理往右倒的情況
        {
            if(dominoes[i] == 'R')
            {
                falling = true;
                indexCount = 0;
            }
            else if(dominoes[i] == 'L' && falling == true)
            {
                indexCount++;
                if(indexCount % 2 == 0)
                {
                    dominoes[i-(indexCount/2)] = '!';
                }
                else
                {
                    dominoes[i-(indexCount/2)-1] = ',';
                }
                falling = false;
            }
            else if(falling == true)
            {
                dominoes[i] = 'R';
                indexCount++;
            }

        }

        falling = false;
        for(int i = len-1; i >= 0; i--)//再處理往左倒的情況
        {
            if(dominoes[i] == 'L')
            {
                falling = true;
            }
            else if(dominoes[i] == '!' || dominoes[i] == ',')
            {
                if(dominoes[i] == '!')
                {
                    dominoes[i] = '.';
                }
                else
                {
                    dominoes[i] = 'R';
                }
                falling = false;
            }
            else if(falling == true)
            {
                dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};