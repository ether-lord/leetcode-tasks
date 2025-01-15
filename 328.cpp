#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == nullptr)
        return head;
      ListNode* odd = head;
      ListNode* even_tail = head->next;

      while (even_tail != nullptr && even_tail->next != nullptr) {
        auto next_odd = even_tail->next;
        auto next_even = next_odd->next;


        even_tail->next = next_even;
        even_tail = next_even;

        if (next_odd != nullptr) {
          next_odd->next = odd->next;
          odd->next = next_odd;
          odd = next_odd;
        }
      }

      return head;
    }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  // auto next = head->next;
  // next->next = new ListNode(3);
  // next = next->next;
  // next->next = new ListNode(4);
  // next = next->next;
  // next->next = new ListNode(5);
  // next = next->next;
  // next->next = new ListNode(6);
  // next = next->next;
  // next->next = new ListNode(7);
  // next = next->next;
  // next->next = new ListNode(8);

  auto s = Solution();
  s.oddEvenList(head);

  auto* iter = head;
  while (iter != nullptr) {
    cout << iter->val << endl;
    iter = iter->next;
  }

  return 0;
}