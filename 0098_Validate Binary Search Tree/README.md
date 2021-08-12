## 解題
第一種寫法的概念是,我與右邊subTree中最小的值做比較,如果 root->val 比它還大就不是BST

之後再與左邊subTree中最大的值做比較,如果 root->val 比它還小就不是BST

好處是如果ans為false的話可以不用繼續找下去,但這個寫法需要一堆if來更新**min**與**max**

第二種寫法則是我傳入max與min,如果我這個node的值比min小或比max大,那就不是BST

如果範圍是對的,則繼續比較leftSubTree與rightSubTree

當傳入leftSubTree時,要更新max為該node的值,而傳入rightSubTree時,要更新min為該node的值

