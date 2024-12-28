#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> candies{12, 1, 12};
  int extraCandies = 3;

  vector<bool> result(candies.size());

  int max_candies = 0;
  for (const auto& count : candies)
    max_candies = max(count, max_candies);

  for (const auto& count : candies)
    result.push_back(count + extraCandies >= max_candies);

  return 0;
}