class MyLinkedList
{
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int v) : val(v), next(nullptr) {}
    };
    ListNode* dummyHead;
    int size;

public:
    MyLinkedList()
    {
        dummyHead = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size) return -1;

        ListNode* current = dummyHead;
        for (int i = 0; i <= index; i++)
        {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val)
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode* newNode = new ListNode(val);

        ListNode* current = dummyHead;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = nullptr;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size) return;

        ListNode* newNode = new ListNode(val);
        ListNode* pre = dummyHead;

        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        newNode->next = pre->next;
        pre->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size) return;

        ListNode* pre = dummyHead;
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        ListNode* toDelete = pre->next;
        pre->next = toDelete->next;

        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */