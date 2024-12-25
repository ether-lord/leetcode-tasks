#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s("  hello world  ");

  vector<string> words;
  string result;
  stringstream ss(s);

  while (!ss.eof()) {
    string token;
    getline(ss, token, ' ');
    if (isalpha(token[0]) || isdigit(token[0]))
      words.push_back(token);
  }

  for (auto it = words.rbegin(); it != words.rend(); ++it) {
    if (!result.empty())
      result.append(" ");
    result.append(*it);
  }

  cout << result << endl;

  return 0;
}