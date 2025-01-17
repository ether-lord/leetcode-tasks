#include <algorithm>
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

  int pairSum(ListNode* head) {
    int list_size = 0;
    for (auto* iter = head; iter != nullptr; iter = iter->next, ++list_size);

    auto* middle = head;
    for (int i = 0; i < list_size / 2 - 1; ++i, middle = middle->next);

    auto* tmp = middle->next;
    middle->next = nullptr;
    middle = tmp;

    middle = reverseList(middle);

    int answer = INT32_MIN;
    while (middle != nullptr && head != nullptr) {
      answer = max(middle->val + head->val, answer);
      middle = middle->next;
      head = head->next;
    }

    return answer;
  }
};

int main() {
  ListNode* head = new ListNode(20);
  head->next = new ListNode(2);
  auto next = head->next;
  next->next = new ListNode(3);
  next = next->next;
  next->next = new ListNode(4);
  next = next->next;
  next->next = new ListNode(5000);
  next = next->next;
  next->next = new ListNode(6);
  next = next->next;
  next->next = new ListNode(7);
  next = next->next;
  next->next = new ListNode(8);

  auto s = Solution();
  cout << s.pairSum(head) << endl;

  return 0;
}