#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
  unordered_map<int, int> num_of_occurences;
  unordered_map<int, bool> unique_occurences;

  for (const auto& i : arr) num_of_occurences[i] += 1;

  for (const auto& [num, count] : num_of_occurences) {
    if (unique_occurences.count(count) > 0)
      return false;
    else
      unique_occurences[count] = true;
  }

  return true;
}

int main() {
  vector<int> nums{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  cout << uniqueOccurrences(nums) << endl;
  return 0;
}