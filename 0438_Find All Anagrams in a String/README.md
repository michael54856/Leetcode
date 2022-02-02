## 解題
這題的概念我用的是sliding window的解法

首先會先去遍歷字串s,若s[i]不在p中,則代表需要重新建構一個window

若s[i]在p中,可分為3種情形(counter代表是目前window所含的字母個數,dictionary是p所含的字母個數)

1.counter[index] > dictionary[index] : 代表需要進行收縮,直到遇到多餘的那個英文字母

2.counter[index] == dictionary[index] : 需要進行檢查,若字母個數都一樣,則可以push到ans中,並要收縮一格

3.counter[index] < dictionary[index] : 直接counter[index]加一即可