## 解題
用pivot去紀錄目前這個子字串的左邊在哪裡,如果說遇到一個字元c,上一個字元c在pivot的右邊,代表重複了,如果上一個字元c在pivot的左邊,代表沒重複

一開始將pivot設為0,代表子字串的左邊從0開始

用一個字典去紀錄每個字元的位置[128],一開始初始化為-1(因為一開始假設所有字元都在pivot左邊)

用for迴圈遍歷字串s

s[i] = c, 用字典查看上一個c的位置

在pivot左邊:更新position

在pivot右邊:代表重複了,計算這個子字串的長度是不是目前最大,更新pivot為上一個c的右邊,再更新c的position

complexity:O(n)
