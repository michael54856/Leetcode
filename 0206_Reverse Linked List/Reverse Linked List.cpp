class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr)
        {
            return head;
        }
        
        ListNode* last = head;
        ListNode* current = head->next;
        head->next = nullptr;
        ListNode* temp;
        
        while(current)
        {
            temp = current->next;
            current->next = last;
            last = current;
            current = temp;
        }

        return last;

    }
};