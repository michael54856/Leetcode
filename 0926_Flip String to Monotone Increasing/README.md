## 解題

###(1)2-pass

自己想了一個2-pass的解法,第一次的pass是計算出**左邊1的數量**與**右邊0的數量**

之後再遍歷一次,會計算這每格**左邊1的數量**(讓左邊都是0的花費)與**右邊0的數量**(讓左邊都是1的花費)加起來最小

###(1)1-pass

後面看了一下討論有個更厲害的寫法,甚至空間複雜度可以到O(1)

這邊會使用2個變數:

* ans : 用來儲存答案
* count1 : 用來儲存目前為止1的數量

這邊的策略是這樣,當我遇到1的時候我的ans不會改變,因為後面串上1還是符合題意

而當我遇到0的時候,我會有2個選擇:

一個選擇是讓0不改變,此時我需要把所有的1反轉才能符合題意

另一個選擇是讓0更改為1,此時的花費為之前的最優花費加1