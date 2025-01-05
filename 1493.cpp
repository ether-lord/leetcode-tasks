#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
  int answer = 0;

  bool can_delete = true;

  int i = 0, j = 0;

  while (j < nums.size()) {
    if (nums[j] == 1 || can_delete) {
      can_delete &= nums[j];
      ++j;
      answer = max(answer, j - i - 1);
      continue;
    }
    if (nums[i++] == 0) can_delete = true;
  }

  return answer;
}

int main() {
  vector<int> nums{0};
  cout << longestSubarray(nums) << endl;
  return 0;
}