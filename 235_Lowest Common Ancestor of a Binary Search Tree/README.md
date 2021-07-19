## 解題
原本沒看到是BST所以直接硬用DFS解

後面看到是BST才重寫了一個更好的解法

這邊就不講dfs了,直接講比較好的寫法

## Better Solution

一開始我會固定讓p的val比較小,q的val比較大

利用遞迴的方式去解,如果 p < root < q (這邊指的是value),那這個點一定是**Lowest Common Ancestor**因為p跟q一定會分岔

再來如果 p == root or q == root , 那這個點一定是**Lowest Common Ancestor**,因為另一個會在這個點的下面

再來如果 p > root , 代表兩個點都在root的右邊

再來如果 q < root , 代表兩個點都在root的左邊