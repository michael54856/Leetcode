class Solution
{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
        bool isEven = false;
        int n1 = A.size();
        int n2 = B.size();
        if((n1+n2)%2 == 0)
        {
            isEven = true;
        }
        //判斷是否只看一條
        if(n1 == 0)
        {
           if(n2%2==0)
           {
               return ((double)(B[n2/2]+B[(n2/2)-1]))/2.0;
           }
           else
           {
               return B[n2/2];
           }
        }
        if(n2 == 0)
        {
           if(n1%2==0)
           {
               return ((double)(A[n1/2]+A[(n1/2)-1]))/2.0;
           }
           else
           {
               return A[n1/2];
           }
        }



        int k = (n1+n2+1)/2;

        int l = 0;
        int r = n1;
        //l,r代表的意義是使用幾個元素
        int m1;
        int m2;

        while(true)//m1的範圍為0~n1
        {
            int mid = (l+r) / 2;
            m1 = mid;
            m2 = k-m1;
            if(m2 < 0)
            {
                r = mid;
                continue;
            }
             if(m2 > n2)
            {
                l = mid+1;
                continue;
            }
            if(l == r)
            {
                break;
            }

            if(m1 == 0)//A使用0個元素,B使用k個元素
            {
                if(A[0] >= B[m2-1])
                {
                    //找到了
                    break;
                }
                else//A[0] < B[m2-1],代表還須使用A,m1往右邊找
                {
                    l = mid+1;
                }
            }
            else if(m1 == k)//A使用k個元素,B使用0個元素
            {
                if(B[0] >= A[m1-1])
                {
                    //找到了
                    break;
                }
                else//B[0] < A[m1-1],代表還須使用B,m1往左邊找
                {
                    r = mid;
                }
            }
            else//m1與m2都有數值
            {
                if(m1 == n1)
                {
                    if(B[m2] >= A[m1-1])
                    {
                        break;
                    }
                    else//需要更多B
                    {
                        r = mid;
                    }
                }
                else if(m2 == n2)
                {
                    if(A[m1] >= B[m2-1])
                    {
                        break;
                    }
                    else//需要更多A
                    {
                        l = mid+1;
                    }
                }
                else
                {
                    if(B[m2] >= A[m1-1] && A[m1] >= B[m2-1])
                    {
                        break;
                    }
                    else if(B[m2] < A[m1-1])//要更多B
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid+1;
                    }
                }

            }

        }

        if(m1 == 0)
        {
            if(m2 == n2)
            {
                if(isEven == true)
                {
                    return ((double)(B[m2-1]+A[0]) /2.0);
                }
                return B[m2-1];
            }
            else
            {
                if(isEven == true)
                {
                    return ((double)(B[m2-1]+min(A[0],B[m2])) /2.0);
                }
                return B[m2-1];
            }
        }
        else if(m2 == 0)
        {
            if(m1 == n1)
            {
                if(isEven == true)
                {
                    return ((double)(A[m1-1]+B[0]) /2.0);
                }
                return A[m1-1];
            }
            else
            {
                if(isEven == true)
                {
                    return ((double)(A[m1-1]+min(B[0],A[m1])) /2.0);
                }
                return A[m1-1];
            }
        }
        else if(m1 == n1)
        {
            if(isEven == true)
            {
                return ((double)(max(A[m1-1],B[m2-1])+B[m2]) /2.0);
            }
            return max(A[m1-1],B[m2-1]);
        }
        else if(m2 == n2)
        {
            if(isEven == true)
            {
                return ((double)(max(A[m1-1],B[m2-1])+A[m1]) /2.0);
            }
            return max(A[m1-1],B[m2-1]);
        }
        else
        {
            if(isEven == true)
            {
                return ((double)( max(A[m1-1],B[m2-1]) + min(A[m1],B[m2])) /2.0);
            }
            return max(A[m1-1],B[m2-1]);
        }


        return 0;
    }
};
