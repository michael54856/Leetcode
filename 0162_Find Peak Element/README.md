## 解題
這題最簡單是linear search : O(N)

但一看到這種題目感覺就有O(logN)的解法

因為題目說 nums[i] != nums[i + 1] for all valid i ,所以不會有一直平穩不上升的狀態

可以用類似binary search的方式去解題

我們可以取得[mid],以及[mid+1]

如果[mid] > [mid+1],代表左邊(包含mid)會有一個peak

如果[mid] < [mid+1],代表右邊(不包含mid)會有一個peak

我們可以看一下圖,其中不同顏色的線為各種預測線型,可發現不管怎麼畫都會有peak

## [mid] < [mid+1]

![image](https://github.com/michael54856/Leetcode/blob/main/162_Find%20Peak%20Element/des1.png)

## [mid] > [mid+1]

![image](https://github.com/michael54856/Leetcode/blob/main/162_Find%20Peak%20Element/des2.png)

