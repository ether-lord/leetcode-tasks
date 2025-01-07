#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
  int sum_left = 0;
  int sum_right = 0;
  for (const auto& i : nums) sum_right += i;

  sum_right -= nums[0];

  for (int i = 0; i < nums.size(); ++i) {
    if (sum_left == sum_right) return i;

    if (i == nums.size() - 1) break;

    sum_left += nums[i];
    sum_right -= nums[i + 1];
  }

  return -1;
}

int main() {
  vector<int> nums{0, 0, 1};
  cout << pivotIndex(nums) << endl;
  return 0;
}