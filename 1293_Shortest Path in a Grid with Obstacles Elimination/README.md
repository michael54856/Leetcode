## 解題
這題算hard中滿直觀的,可以從基本的BFS來做延伸

做BFS的時候要多加一項數值,代表還可以衝破障礙的次數

以下的解法可以利用數字的正負號與數值來達成inplace的解法

我們傳obstacleBreak的時候是傳負數,且其絕對值會比正常多1

例如:在這格時,我還可以衝破2個障礙,我的obstacleBreak = -3 , 因為我想讓走過的路都為負數

檢查時有3種情況:

(1) grid[y][x] = 0 , 代表沒走過,且沒障礙,obstacleBreak的值不變,並傳入queue中, 把這格grid[y][x]存為obstacleBreak的值(注意是負的)

(2) grid[y][x] = 1 , 代表沒走過,但有障礙,obstacleBreak加一後傳入queue中, 把這格grid[y][x]存為obstacleBreak + 1 - 10000 , 除了用正負來區分有沒有走過還不夠,我還需要知道那格是否有障礙物,我多減了10000,這樣小於-10000的格子代表走過了且有障礙物

(3) 其他, 代表走過了 , 先判斷有沒有小於10000,之後分別判斷obstacleBreak的值,看能不能再加進queue中,並更新grid[y][x]

第一種與第二種比較簡單,放入queue中並在grid