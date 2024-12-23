#include <iostream>
#include <string>

using namespace std;

int main() {
  string result;
  string word1("aaaaaaaaaaaaaaaaaaaaas");
  string word2("f");

  auto word1_it = word1.begin();
  auto word2_it = word2.begin();

  while (word1_it != word1.end()) {
    result.push_back(*word1_it++);

    if (word2_it != word2.end())
      result.push_back(*word2_it++);
  }

  while(word2_it != word2.end())
      result.push_back(*word2_it++);

  cout << result << endl;
  return 0;
}