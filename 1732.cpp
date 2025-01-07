#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int largestAltitude(vector<int>& gain) {
  int highest = 0;
  int current = 0;
  for (const auto& i : gain) {
    current += i;
    highest = max(current, highest);
  }

  return highest;
}

int main() {
  vector<int> nums{-4,-3,-2,-1,4,3,2};
  cout << largestAltitude(nums) << endl;
  return 0;
}