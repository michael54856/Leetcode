class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == nullptr)
        {
            return head;
        }
        bool isEven = true;
        ListNode* odd_Head = new ListNode();
        ListNode* currenOdd = odd_Head;

        ListNode* even_Head = new ListNode();
        ListNode* currenEven = even_Head;

        while(head)
        {
            if(isEven == true)
            {
                currenEven->next = head;
                currenEven = currenEven->next;
            }
            else
            {
                currenOdd->next = head;
                currenOdd = currenOdd->next;
            }
            isEven = !isEven;
            head = head->next;
        }
        currenOdd->next = nullptr;
        odd_Head = odd_Head->next;
        even_Head = even_Head->next;
        currenEven->next = odd_Head;
        return even_Head;


    }
};