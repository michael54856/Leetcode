## 解題
先算出all = 1+2+3.......+n

遍歷nums,把sum加上nums[i]

如果nums[i]重複了,就把nums[i]放入答案

之後把all - sums 再加上 ans[0] 就是另一個答案
