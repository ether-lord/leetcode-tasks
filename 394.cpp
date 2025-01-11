#include <stdlib.h>

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
  string answer;

  stack<int> multipliers;
  stack<string> strings;

  strings.push(string());

  for (int i = 0; i < s.length(); ++i) {
    while (isalpha(s[i])) strings.top().push_back(s[i++]);

    if (isdigit(s[i])) {
      string num_str;
      while (isdigit(s[i])) num_str.push_back(s[i++]);
      multipliers.push(stoi(num_str));
    }

    if (s[i] == '[') strings.push(string());

    if (s[i] == ']') {
      int num = multipliers.top();
      string top_str = strings.top();
      string str;

      for (int i = 0; i < num; ++i) str.append(top_str);

      multipliers.pop();
      strings.pop();
      strings.top().append(str);
    }
  }

  return strings.top();
}

int main() {
  cout << decodeString("2[abc]3[cd]ef") << endl;
  // decodeString("3[a]2[bc]");
  return 0;
}