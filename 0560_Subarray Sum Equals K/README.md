## 解題
這邊的概念是用prefixSum去解

如果我目前的prefixSum是dp[i],那麼我可以去尋找前面有沒有一段他的prefixSum是dp[i]-k

如此一來就能獲得一個sum為k的subsequence

會透過unordered_map去實現