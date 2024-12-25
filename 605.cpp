#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> flowerbed{1,0};
  int n = 1;

  if (n == 0)
    return true;
  
  if (flowerbed.size() == 1)
    return flowerbed[0] == 0 && n <= 1;
  
  int prev_n = n;
  for (int i = 0; i < flowerbed.size(); i++) {
    if(i == 0)
      n -= int(flowerbed[i] == 0 && flowerbed[i + 1] == 0);
    else if(i == flowerbed.size() - 1)
      n -= int(flowerbed[i] == 0 && flowerbed[i - 1] == 0);
    else
      n -= int(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0);

    if (prev_n != n && i < flowerbed.size())
      flowerbed[i] = 1;
    prev_n = n;

    if (n == 0)
      break;
  }

  cout << n << endl;

  return n == 0;
}