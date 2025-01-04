#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
  int answer = 0;
  int current_k = k;

  int i = 0;
  int j = 0;

  while (j < nums.size()) {
    while (j < nums.size() && (nums[j] == 1 || current_k > 0)) {
      current_k -= nums[j] == 0 ? 1 : 0;
      ++j;
    }
    answer = max(answer, j - i);

    while (j < nums.size() && (nums[j] == 0 && current_k == 0)) {
      current_k += nums[i++] == 0 ? 1 : 0;
      current_k = min(current_k, k);
      j = max(j, i);
    }
  }

  return answer;
}

int main() {
  vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  int k = 3;
  cout << longestOnes(nums, k) << endl;
  return 0;
}