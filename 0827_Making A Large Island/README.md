## 解題
這題是久違的HARD題,但理解題目要什麼的話還滿直觀的

這邊提供一個複雜度o(n^2)的解法(n為正方形之邊長)

這邊為了節省記憶體,我們會利用他給予的grid來存放必要的資料,由於grid中只會出現0,1,所以我們可以拿2以上的數字來當作島嶼編號

首先我們遍歷整個正方形,如果碰到**1**代表遇到一個還沒走過的島嶼,利用BFS來把島嶼走完,並把島嶼中的1更換為編號

這邊要使用一個額外的陣列**int islandList[100000]**來存放對應編號的島嶼大小(一開始開10000不太夠用,開到100000才AC)

如果碰到**0**,代表這是一個連接點,這個連接點可以連接**上,下,左,右**周圍的島嶼(如果有的話)

所以如果**上,下,左,右**是**1**還沒走過的話,計算前要先call **BFS**走一下

但有個陷阱是,左邊連的島嶼跟右邊連的島嶼有可能是同一個島,這樣子數字會多加一次,所以要額外做判斷,如果連過就不相加

之後取得最大相連後的數字就可以了~

但要注意有個額外狀況就是沒有出現**0**,整張圖就是一個島,此時要輸出島的大小(也就是地圖的大小)

執行速度上還滿快的,贏過了**99.73%**

而記憶體使用量方面,贏過了**97.97%**


