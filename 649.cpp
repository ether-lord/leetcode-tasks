#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
      queue<char> votes;
      int dires = 0, radiants = 0;

      for (const auto& c : senate) {
        votes.push(c);
        dires += c == 'D';
        radiants += c == 'R';
      }

      int d_to_discard = 0;
      int r_to_discard = 0;
      
      while (dires > 0 && radiants > 0) {
        auto team = votes.front();
        votes.pop();

        bool is_dire = team == 'D';
        bool is_radiant = !is_dire;

        if (is_dire) {
          if (d_to_discard == 0)
            votes.push('D'), ++r_to_discard;
          else 
            --d_to_discard, --dires;
        } else {
          if (r_to_discard == 0)
            votes.push('R'), ++d_to_discard;
          else 
            --r_to_discard, --radiants;
        }
      }

      return dires == 0 ? "Radiant" : "Dire";
    }
};

int main() {
  auto s = Solution();
  cout << s.predictPartyVictory("DRRDRDRDRDDRDRDR") << endl;
  return 0;
}