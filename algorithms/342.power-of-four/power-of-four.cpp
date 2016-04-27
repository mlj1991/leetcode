#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
      int x = 1431655765; // 4^0 + 4^1 + 4^2 + ... + 4^15
      return ((num&x) == num) && ((num&(num-1)) == 0) && (num != 0);
    }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int num;
  cin >> num;
  cout << Solution().isPowerOfFour(num);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
