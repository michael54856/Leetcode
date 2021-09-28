## 解題
這題想了一個inplace的解法

用兩個指標even_pointer與odd_pointer來記錄奇數與偶數現在的格子位置

even_pointer會0,2,4,6,8......的移動,而odd_pointer會1,3,5,7,9......的移動

even_pointer會指向是奇數的格子,而odd_pointer會指向是偶數的格子

都找到後進行交換,之後再繼續執行