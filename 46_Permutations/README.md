## 解題
所有數字都是不同的,要計算吃所有排列

用dfs的方式去計算,會設定一個position,代表現在的位置,再把position後的所有格子都與position交換並繼續遞迴

遞迴完成後要把交換的資料換回來