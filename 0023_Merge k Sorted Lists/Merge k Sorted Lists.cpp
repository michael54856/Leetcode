class Solution
{
public:

    ListNode* mergeList(vector<ListNode*>& lists, int start_, int end_)
    {
        if(start_ == end_)
        {
            return lists[start_];
        }

        int mid = (start_+end_) / 2;
        ListNode* left = mergeList(lists,start_,mid);
        ListNode* right = mergeList(lists,mid+1,end_);

        ListNode* head = new ListNode();
        ListNode* current = head;

        while(left && right)
        {
            if(left->val < right->val)
            {
                current->next = left;
                current = current->next;
                left = left->next;
            }
            else
            {
                current->next = right;
                current = current->next;
                right = right->next;
            }
        }
        while(left)
        {
            current->next = left;
            current = current->next;
            left = left->next;
        }
        while(right)
        {
            current->next = right;
            current = current->next;
            right = right->next;
        }
        return head->next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int len = lists.size();
        if(len == 0)
        {
            return nullptr;
        }

        return mergeList(lists,0,len-1);

    }
};