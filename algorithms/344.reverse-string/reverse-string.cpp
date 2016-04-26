#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
      for (int i = 0; i != s.size()/2; ++i) {
        int j = s.size()-i-1;
        char k = s[i]; s[i] = s[j]; s[j] = k;
      }
      return s;
    }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  string s;
  cin >> s;
  cout << Solution().reverseString(s);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
