## 解題
核心想法是這樣,如果遇到0.sum--,遇到1,sum++

所以sum的範圍是+len ~ -len

會需要建立一個 2*len+1 的陣列,用來存放一些資訊

遍歷nums,若sum==0,則更新ans

若sum != 0,會先看看這個sum有沒有出現過

沒有出現的話則把這個位置 i 放進 arr[sum+len]

若這個sum有出現的話,代表我們可以減去那個index前面的部分,來使0,1的數量一樣

例如 arr[2] = 3 , 代表在 index = 3 時 , sum = 2 , nums[0]+nums[1]+nums[2]+nums[3] = 2

假如在 index = 8時 ,sum = 2 , 那麼 nums[0]+nums[1]+nums[2]+nums[3]+nums[4]+nums[5]+nums[6]+nums[7]+nums[8] = 2

我們只要將前面的nums[0]+nums[1]+nums[2]+nums[3]去掉,那麼sum就會等於0了,由此可得最長的substring
