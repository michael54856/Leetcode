## 解題
單向BFS:

概念是使用BFS去尋找出最短的路徑,只是當我們在找下一個的時候

必須將每一個字元都替換成a~z,並使用hashSet的方式看有沒有在wordList中,有的話就可以放入到Queue中

但是能夠放入Queue的條件有兩個

(1)沒有被使用過

(2)不能夠形成cycle

我們可以用hashMap來做檢查

如果我的字串s是透過替換第i個字元所錢進來的,那麼我就無法再透過替換第i個字元來前往下一步

透過hashMap的方式儲存是替換第幾個字元來的

雙向BFS:

為單向的優化,有空的時候再寫寫看

