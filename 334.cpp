#include <iostream>
#include <vector>

using namespace std;

int GetPivot(int& i, int& j, const vector<int>& nums);

int main() {
  vector<int> nums({1,1,-2,6});

  if (nums.size() < 3) return false;

  int i = 0;
  int j = 1;
  int k = 2;

  int pivot = GetPivot(i, j, nums);
  k = j + 1;

  if (k >= nums.size())
    return false;

  if (nums[i] < nums[j] && nums[j] < nums[k]) return true;

  while (k < nums.size()) {
    while (k < nums.size() - 1 && nums[j] >= nums[k] && nums[k] > nums[i]) j = k++;
    pivot = nums[j];

    if (nums[i] < nums[j] && nums[j] < nums[k]) return true;

    int prev_pivot_index = j;
    int new_pivot = GetPivot(++j, ++k, nums);

    if (j == -1)
      return false;

    if (new_pivot < pivot) {
      pivot = new_pivot;
      i = j;
      j = k++;
    } else {
      j = prev_pivot_index;
    }
  }

  return false;
}

int GetPivot(int& i, int& j, const vector<int>& nums) {
  for (;j < nums.size() - 1 && nums[i] >= nums[j]; ++i, ++j);
  if (j < nums.size())
    return nums[j];
  else {
    j = i = -1;
    return 0;
  }
}
