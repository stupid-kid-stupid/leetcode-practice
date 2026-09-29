#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;

        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                ListNode* valcur = cur->next;
                cur->next = cur->next->next;
                delete valcur;
            }
            else
            {
                cur = cur->next;
            }

        }

        ListNode* newhead = dummy->next;
        delete dummy;

        return newhead;
    }
};

int main()
{
    Solution solution;
    // 创建三个节点
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);


    // 串起来
    head->next = second;
    second->next = third;

    head = solution.removeElements(head, 2);

    // 遍历
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}