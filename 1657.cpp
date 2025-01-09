#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool closeStrings(string word1, string word2) {
  if (word1.length() != word2.length()) return false;

  unordered_map<char, int> word1_symbols;
  unordered_map<int, int> word1_symbols_count;
  unordered_map<char, int> word2_symbols;
  unordered_map<int, int> word2_symbols_count;

  for (const auto& c : word1) word1_symbols[c] += 1;

  for (const auto& [ch, count] : word1_symbols) word1_symbols_count[count] += 1;

  for (const auto& c : word2) {
    word2_symbols[c] += 1;
    if (word1_symbols.count(c) == 0) return false;
  }

  for (const auto& [ch, count] : word2_symbols) word2_symbols_count[count] += 1;

  return equal(word1_symbols_count.begin(), word1_symbols_count.end(),
               word2_symbols_count.begin(),
               [&](const auto& a, const auto& b) {
                  return word2_symbols_count.count(a.first) > 0 && word2_symbols_count[a.first] == a.second;
               });
}

int main() {
  cout << closeStrings("cabbba", "abbccc") << endl;
  return 0;
}