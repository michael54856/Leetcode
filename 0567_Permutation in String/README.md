## 解題
這題也是使用sliding window的解法

一開始會先紀錄s1各個英文字母的出現次數

之後會遍歷s2,當看到s2[i]的時後

如果s2[i]沒有出現在s1內,則window重新開始,出現次數都歸零

如果s2[i]有出現在s1內,會將其出現次數加一,若出現次數與s1的一樣時,則檢查所有26個是否都一樣

如果出現次數大於s1的次數時,會收縮window直到同一個字母,將沿路的出現次數扣掉