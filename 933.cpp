#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
      lower_bound = t - 3000;
      pings.push(t);
      while (pings.front() < lower_bound)
        pings.pop();

      return pings.size();
    }
private:
  queue<int> pings;
  int lower_bound = 0;
};

int main() {
  auto r = RecentCounter();

  vector<int> nums({1, 100, 3001, 3002});
  for (const auto& i : nums)
    cout << r.ping(i) << endl;

  return 0;
}