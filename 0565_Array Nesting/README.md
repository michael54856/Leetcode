## 解題
這題與之前寫過的APCS歷屆基本上一樣,一個是算有幾個group,一個是要取得最大的group

遍歷整個數列,如果nums[i]不為-1代表還沒被加入一個group,並開始建構一個新的group

一開始把i紀錄下來當作起點,然後一直看下去,途中要把走過的地方設為-1

如果回到起點代表完成一個group