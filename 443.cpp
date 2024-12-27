#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {
  int sequence_begin = 0;
  int sequence_end = 0;
  int caret = 0;

  while (sequence_end < chars.size()) {
    while (sequence_end < chars.size() && chars[sequence_begin] == chars[sequence_end]) ++sequence_end;
    chars[caret++] = chars[sequence_begin];
    
    if (sequence_end - sequence_begin > 1) {
      auto length_str = to_string(sequence_end - sequence_begin);
      for (const auto& c : length_str)
        chars[caret++] = c;
    } 

    sequence_begin = sequence_end;

  }

  return caret;
}

int main() {
  vector<char> chars{'a', 's', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'a'};
  cout << compress(chars) << " - " << endl;
  
  for (const auto& ch : chars)
    cout << ch << endl;

  return 0;
}