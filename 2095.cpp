struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 1;
        ListNode* premid = new ListNode(0, head);
        ListNode* iter = head;

        while (iter->next != nullptr) {
            ++len;
            if (len % 2 == 0) {
                premid = premid->next;
            }
            iter = iter->next;
        }

        if (len == 1) {
            head = nullptr;
            return head;
        }

        auto mid_iter = premid->next;
        premid->next = mid_iter->next;
        delete mid_iter;

        return head;
    }
};