#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
  map<int, int> occurrences;

  for (const auto& i : nums1)
    occurrences[i] = 1;

  for (const auto& i : nums2) {
    if (occurrences.count(i) == 1 && occurrences[i] != 2)
      occurrences[i] = -1;
    else if(occurrences[i] != -1)
      occurrences[i] = 2;
  }

  vector<vector<int>> answer(2);

  for (const auto& [number, count] : occurrences) {
    if (count == 1)
      answer[0].push_back(number);
    else if (count == 2)
      answer[1].push_back(number);
  }

  return answer;
}

int main() {
  vector<int> n1{-80,-15,-81,-28,-61,63,14,-45,-35,-10};
  vector<int> n2{-1,-40,-44,41,10,-43,69,10,2};
  findDifference(n1, n2);
  return 0;
}