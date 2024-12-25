#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums({3,4, 1});

  vector<int> answer(nums.size());
  vector<int> productions(nums.size());

  productions[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    productions[i] = productions[i - 1] * nums[i]; 
  }
  productions[nums.size() - 1] = nums[nums.size() - 1];

  answer[nums.size() - 1] = productions[nums.size() - 2];
  for (int i = nums.size() - 2 ; i > 0; --i) {
    answer[i] = productions[i + 1] * productions[i - 1];
    productions[i] = productions[i + 1] * nums[i];
  }
  answer[0] = productions[1];

  // for (auto& i : answer)
  //   cout << i << endl;

  
  return 0;
}