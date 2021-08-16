## 解題
標準sliding window的題目

首先我會先建立**sCounting[128],tCounting[128]**代表s與t的字元出現次數(因為ascii的範圍所以設128)

一開始先遍歷t,把tCount建立好

原本我是打算用for(int i = 0; i < 26; i++)這個迴圈去檢查出現次數是否相同,如果是的話就是window subString

但這樣每次檢查都需要用這個迴圈,會消耗許多效能,之後我想了一個作法

我使用一個變數叫做**matchCount**,是用來記錄符合t字串的次數

一開始先把r與l設成0,r會往右邊移動,直到matchCount = t.size(),也就是形成一個符合題意的window substring

過程中如果遇到t也有出現的字元sCounting[s[r]]就會加一,如果(sCounting[s[r]] < tCounting[s[r]])代表是一個關鍵的字元,matchCount就加一

而當matchCount = t.size()時,我的l也會開始往右移動,過程中如果遇到t沒出現的字元就直接跳過,如果遇到t出現的字元,會有兩種情況

第一種情況是 **sCounting[s[l]] > tCounting[s[l]]** ,代表就算去掉這個字元還是能夠符合window substring

第一種情況是 **sCounting[s[l]] = tCounting[s[l]]** ,代表這個字元是不能被去除的,不然會不符合window substring

如果遇到第二種情況,就看是不是這個subString更短,是的話就覆蓋,並把l與r加一,尋找下個可能