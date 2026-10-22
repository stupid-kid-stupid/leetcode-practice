
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode dummy(0, head);    // dummy 是 ListNode 对象
        ListNode* prev = &dummy;    // prev 是 ListNode* 指针

        while(prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            //交换 first 和 second
            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }
        
        return dummy.next;
    }
};