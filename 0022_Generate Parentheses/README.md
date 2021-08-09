## 解題
用dfs可以直接解決,這邊會有兩個比較重的的數字

* leftParenthesisInString = string中還沒被配對的左括號數量
* leftParenthesisCount = 不管有沒有配對,在string中的左括號數量

當leftParenthesisInString為0時,代表還沒被配對的左括號為0,所以這種情況下只能填入'('

而當leftParenthesisInString > 0時,我們有可能填入左括號或右括號,但如果左括號已經填入n次,那就不能再填了!