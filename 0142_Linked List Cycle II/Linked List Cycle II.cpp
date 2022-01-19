class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode *current = head;
        while(current)
        {
            if(current->val < 0)
            {
                if(current->val <= -100000)
                {
                    break;
                }
                current->val += -100000;
            }
            else
            {
                if(current->val >= 100000)
                {
                    break;
                }
                current->val += 100000;
            }
            current = current->next;
        }
        return current;
    }
};