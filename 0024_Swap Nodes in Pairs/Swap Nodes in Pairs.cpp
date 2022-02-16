class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == nullptr)
        {
            return head;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* last = dummy;
        ListNode* current = head;
        while(current)
        {
            if(current->next == nullptr)
            {
                last->next = current;
                break;
            }
            else
            {
                ListNode* theNext = (current->next)->next;
                last->next = current->next;
                (last->next)->next = current;
                current->next = theNext;
                last = current;
                current=current->next;
            }
        }
        return dummy->next;
    }
};