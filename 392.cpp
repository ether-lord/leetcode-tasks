#include <iostream>
#include <vector>

using namespace std;

bool isSubsequence(string s, string t) {
  int s_len = s.length();
  for (int pt = 0, ps = 0;pt < t.length(); pt++) {
    if (t[pt] != s[ps]) {
      continue;
    }
    if (++ps == s_len)
      return true;
  }

  return false;
}

int main() {
  string s("asb,kdac");
  string t("asmdbaos,kdac");
  cout << isSubsequence(s, t) << endl;
  return 0;
}