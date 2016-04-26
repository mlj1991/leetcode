#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
      if (n == 2) return 1;
      if (n == 3) return 2;
      int x = n / 3;
      int y = n % 3;
      int p;
      int base;
      if (y == 0) {
        p = x; base = 1;
      } else if (y == 1) {
        p = x-1; base = 4;
      } else if (y == 2) {
        p = x; base = 2;
      }
      return round(pow(3, p) * base);
    }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int n;
  cin >> n;
  cout << Solution().integerBreak(n);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
