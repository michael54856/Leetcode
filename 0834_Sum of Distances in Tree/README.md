## 解題
核心解法為2-pass的DFS

第一個DFS是在建立2個資料

1. 這個node以下的所有node數量(包含這個node本身)
2. 從下方到這個node的所有path數量

關於資料的儲存我是使用adjacency list,而哪一點要當root可以自己定義,我這邊是直接把0當作root

建構時,會先從底層的leaf開始建構,0會最後建構完成

算node數量比較簡單,就直接把所有children的node數量加起來並加1(加上自己)

算path時,也是要看所有children的path,假如我的某個child,從下方到他的path有a個,而此點下方的node有b個,那麼從這個child到我的所有path就是a+b

先想像所有的點都集中到child需要花費a的成本,之後再把這b個node往上移一格,如此就會是a+b

再來第2個DFS是計算答案

傳入遞迴時,有2個比較重要的資訊,一個是從上面來的有幾個node,另一個是從上面來到這個點有多少path

要繼續遞迴的話就要算出這兩個資訊才能繼續下去,計算比較複雜,詳細計算公式可看程式碼

