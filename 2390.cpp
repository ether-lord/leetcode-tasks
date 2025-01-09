#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string removeStars(string s) {
  stack<char> chars;

  for (const auto& ch : s) {
    if (ch != '*') chars.push(ch);
    else chars.pop();
  }
  
  s.clear();
  while (!chars.empty()) {
    s.append({chars.top()});
    chars.pop();
  }

  reverse(s.begin(), s.end());
  return s;
}

int main() {
  cout << removeStars("erase*****") << endl;
  return 0;
}