## 解題
用遞迴的方式去走訪樹,先走到最底部,左右2個subtree會分別回傳一個數字

如果回傳的數字為0,代表那個subtree的數字全是0,將那邊的child設為nullptr

如果>0代表需要保留

要留意的是有可能答案會是nullptr,所以回到最一開始後要判斷一下