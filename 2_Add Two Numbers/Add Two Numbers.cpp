class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *ans = new ListNode();
        ListNode *a = ans;
        short carry = 0;
        
        int t;
        while(l1 || l2)
        {
            t = 0;
            if(l1)
            {
                t += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                t += l2->val;
                l2 = l2->next;
            }
            t += carry;
            carry = t / 10;
            
            a->next = new ListNode(t%10);
            a = a->next;

        }
        
        if(carry)
        {
            a->next = new ListNode(1);
        }
        
        ans = ans->next;
        return ans;

    }
};