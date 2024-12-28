#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
  int l = 0;
  int r = 0;
  int zeros = 0;

  while (r < nums.size()) {
    while (r < nums.size() && nums[r] == 0) {
      ++zeros;
      ++r;
    }

    while (r < nums.size() && nums[r] != 0)
      nums[l++] = nums[r++];
  }

  r = nums.size() - 1;
  while (zeros-- > 0)
    nums[r--] = 0;
}

int main() {
  vector<int> nums{0, 0, 0, 1, 0, 0, 0 ,0 ,0 };
  moveZeroes(nums);
  for (auto& i : nums)
    cout << i << endl;
  return 0; 
}