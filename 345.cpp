#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  string s("leetcode");
  
  string result;
  vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

  auto is_vowel = [&](const char& ch){
    return find(vowels.begin(), vowels.end(), ch) != vowels.end();
  };

  int left = 0, right = s.length() - 1;
 
  while (left < s.length()) {
    for (;right >= 0 && !is_vowel(s[right]); --right);

    if (is_vowel(s[left])){
      result.push_back(s[right--]);
      left++;
    } else {
      result.push_back(s[left++]);
    }
  }
  
  return 0;
}