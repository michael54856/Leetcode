## 解題
一開始先找到一個左右不相等的index,作為建構的起點,如果arr[i] > arr[i+1],那麼flag會設為true,而arr[i] < arr[i+1],那麼flag會設為false

之後會根據flag的狀態來判別arr[i]與arr[i+1]的關係是否符合題意,符合的話counter會加一,並繼續往後做

如果不符合的話,會根據現在的位置往右找,找到第一個arr[i] != arr[i+1],之後又開始新的一輪

