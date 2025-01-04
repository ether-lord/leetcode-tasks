#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
  int current_max = 0;
  for (int i = 0; i < k; ++i)
    current_max += nums[i];

  int current_sum = current_max;
  for(int i = 0, j = k - 1;j < nums.size() - 1;) {
    current_sum -= nums[i++];
    current_sum += nums[++j];

    current_max = max(current_max, current_sum);
  }

  return static_cast<double>(current_max) / k;
}

int main() {
  vector<int> nums{5, 100};
  int k = 1;
  cout << findMaxAverage(nums, k) << endl;
  return 0;
}