## 解題

### 1.O(n):

如果我們知道left subArray的數字都比right subArray的數字小,代表這是一個可以被獨立排列的block(因為不管怎麼排都比右邊小,所以是對的)

所以我們用一個陣列去紀錄left subArray中最大的值,再記錄right subArray中最小的值

預設ans = 1(因為最少一定要1個block,由最右邊的判斷貢獻來的)

iterate從 0 ~ len-2 , if(max_from_left[i] <= min_from_right[i+1]) ans++

### 2.O(nlogn):

去做stable的排序,再去比對index

indexSum = 排序後的index, normalSum = 0+1+2+3+4+4......

if(indexSum == normalSum) ans++

### 3.O(nlogn):

直接做排序(不管stable)

因為我排序後的數字可以切成block,如果再以特定順序做排列的話,就是原來的陣列

if(originalSum == sum) ans++
