#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
  vector<int> answer;
  stack<int> asteroids_stack;

  for (const auto& i : asteroids) {
    if (asteroids_stack.empty()) {  
      asteroids_stack.push(i);
      continue;
    }

    if (asteroids_stack.top() > 0 && i < 0) {
      cout << asteroids_stack.top() << ' ' << i << endl;
      while (!asteroids_stack.empty() && asteroids_stack.top() < abs(i) && asteroids_stack.top() > 0)
        asteroids_stack.pop();

      if (!asteroids_stack.empty() && asteroids_stack.top() == abs(i))
        asteroids_stack.pop();
      else if (asteroids_stack.empty() || asteroids_stack.top() < 0)
        asteroids_stack.push(i);
    } else {
      asteroids_stack.push(i);
    }
  }

  while (!asteroids_stack.empty()) {
    answer.push_back(asteroids_stack.top());
    asteroids_stack.pop();
  }

  reverse(answer.begin(), answer.end());
  return answer;
}

int main() {
  vector<int> asteroids{-8, -9, 100, -100};
  auto answer = asteroidCollision(asteroids);
  fputc('[', stdout);
  for (const auto& i : answer) {
    fprintf(stdout, "%d ", i);
  }
  fputc(']', stdout);
  putc('\n', stdout);
  return 0;
}