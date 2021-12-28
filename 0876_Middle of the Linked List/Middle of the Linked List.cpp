class Solution {
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast->next)
            {
                fast = fast->next;
            }
            else
            {
                break;
            }
        }
        return slow;
        
    }
};