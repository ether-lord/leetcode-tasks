#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string str1("aaaaaa");
  string str2("aaa");

  if (str1.length() == 0 || str2.length() == 0) return 0;

  auto shortest_str = std::min(str1, str2);
  auto longest_str = std::max(str1, str2);

  vector<string> prefixes;
  for (int pref_size = 1; pref_size <= shortest_str.length(); ++pref_size) {
    if (str1.length() % pref_size != 0 || str2.length() % pref_size != 0) continue;
    string prefix = shortest_str.substr(0, pref_size);
    // cout << prefix << endl;
    prefixes.push_back(prefix);
  }

  string result;
  for (const auto& prefix : prefixes) {
    size_t len = prefix.length();
    bool is_gcd = true;

    for (auto i = 0; i < longest_str.length(); i += len) {
      auto substring = longest_str.substr(i, len);
      if (substring.compare(prefix) != 0) {
        is_gcd = false;
        break;
      }
    }

    if (!is_gcd)
      continue;

    for (auto i = 0; i < shortest_str.length(); i += len) {
      auto substring = shortest_str.substr(i, len);
      if (substring.compare(prefix) != 0) {
        is_gcd = false;
        break;
      }
    }

    if (is_gcd)
      result = prefix;
  }

  cout << result << endl;

  return 0;
}