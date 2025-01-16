#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;

    auto* iter = head->next;
    auto* new_head = head;
    new_head->next = nullptr;

    while (iter != nullptr) {
      auto* tmp = iter->next;

      iter->next = new_head;
      new_head = iter;

      iter = tmp;
    }

    return new_head;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  auto next = head->next;
  next->next = new ListNode(3);
  next = next->next;
  next->next = new ListNode(4);
  next = next->next;
  next->next = new ListNode(5);
  next = next->next;
  next->next = new ListNode(6);
  next = next->next;
  next->next = new ListNode(7);
  next = next->next;
  next->next = new ListNode(8);

  auto s = Solution();
  head = s.reverseList(head);

  auto* iter = head;
  while (iter != nullptr) {
    cout << iter->val << endl;
    iter = iter->next;
  }

  return 0;
}