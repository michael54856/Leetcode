## 解題
這題雖然是個簡單的題目,但有個額外的限制是必須使用constant memorie

我的解題策略如下,我會有兩個bool,**leftHaveZero**與**topHaveZero**

一開始會先掃matrix[0]這個row(最上面那條從左掃到右),如果有0的話**topHaveZero**設成true

再掃最左邊那條,從上掃到下,如果有0的話**leftHaveZero**設成true

之後從[1][1]開始掃到右下角,如果matrix[i][j]為0的話,那就把那格的左邊與上面設成0,也就是matrix[i][0]與matrix[0][j]設成0

掃完之後我們再看matrix[i][0](左邊開頭)是否為0,是的話把整列設成0

再看matrix[0][j](上面開頭)是否為0,是的話把整行設成0

之後再看**topHaveZero**是否為true,是的話把最上面那列全部設成0

再看**leftHaveZero**是否為true,是的話把最左邊那行全部設成0

這兩個要放到最後面再檢查,否則要填0的行列會亂掉