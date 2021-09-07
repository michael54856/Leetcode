## 解題
有dfs的解法與優化過的dp解法

(1)dfs

會記錄minVal與maxVal,代表這個sub tree能使用的數字範圍,此時用一個for迴圈把這個subTree的root value設定為minVal到maxVal

之後根據i建構這個subTree的left child(更新maxVal)與 right child(更新minVal)

最後用2維的for迴圈把所有可能建構出來,並push進vector內

(2)dp

基本上是從上面dfs的寫法去改的,只是有很多subTree會重複算到,所以可以把算過的紀錄一下

因為n <= 8, 所以我開一個  dp[9][9] ,用來對應minVal與maxVal (dp[minVal][maxVal])

一開始進入遞迴時會先檢查有沒有算過,有的話直接回傳dp[minVal][maxVal



