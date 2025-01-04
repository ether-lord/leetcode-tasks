#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool IsVowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int maxVowels(string s, int k) {
  int answer = 0;
  for (int i = 0; i < k; ++i)
    answer += static_cast<int>(IsVowel(s[i]));

  int current_max = answer;

  for (int i = 0, j = k - 1; j < s.length();) {
    current_max -= IsVowel(s[i++]);
    if (current_max < 0)
     current_max = 0;
    current_max += IsVowel(s[++j]);

    answer = max(answer, current_max);
  }

  return answer;
}

int main() {
  string s = "tryhard";
  int k = 4;
  cout << maxVowels(s, k) << endl;
  return 0;
}