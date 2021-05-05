## 解題
![image](https://https://github.com/michael54856/Leetcode/tree/main/4_Median%20of%20Two%20Sorted%20Arrays/strategy.jpg)

如上圖,數列A有n1個elements,而數列B有n2個elements

構成中位數時,A提供前面m1個elements,而B提供前面m2個elements (因為index從0開始所以最大的index為[m1-1],[m2-1])

假設(n1+n2+1)/2 = k

在總和為奇數時, k-1 = 中位數

在總和為偶數時, k-1 = 左中位數

我們假設 (m1+m2) = k = (n1+n2+1)/2

計算一下得到 m2 = k - m1

所以我們可以透過binary search尋找m1,並透過m2 = k - m1得到 m2

我們要檢查B[m2] >= A[m1-1] 和 A[m1] >= B[m2-1],如果符合我們就找到m1與m2了



