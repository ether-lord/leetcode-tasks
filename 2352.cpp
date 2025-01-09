#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
  unordered_map<string, int> rows;

  for (const auto& row : grid) {
    string row_str;

    for (const auto& i : row) row_str.append(to_string(i)).append(" ");

    rows[row_str] += 1;
    row_str.clear();
  }

  int answer = 0;

  for (int col = 0; col < grid.size(); ++col) {
    string col_str;

    for (int row = 0; row < grid.size(); ++row)
      col_str.append(to_string(grid[row][col])).append(" ");

    answer += rows.count(col_str) > 0 ? rows[col_str] : 0;
    col_str.clear();
  }

  return answer;
}

int main() {
  vector<vector<int>> grid{{11, 1}, {1, 11}};
  cout << equalPairs(grid) << endl;
  return 0;
}