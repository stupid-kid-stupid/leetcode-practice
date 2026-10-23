
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        for (ListNode* currA = headA; currA != nullptr; currA = currA->next)
        {
            for (ListNode* currB = headB; currB != nullptr; currB = currB->next)
            {
                if (currA == currB)
                    return currA;
            }
        }
        return nullptr;

    }
};

class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB)
        {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;  // 相交则返回交点，不相交则返回 nullptr
    }
};