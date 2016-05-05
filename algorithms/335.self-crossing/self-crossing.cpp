#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
  void move(int d, pair<int, int>& p, int x) {
    if (d == 0) p.second += x;
    else if (d == 1) p.first -= x;
    else if (d == 2) p.second -= x;
    else if (d == 3) p.first += x;
  }

  int value(int d, pair<int, int>&p) {
    if (d == 0) return p.second;
    else if (d == 1) return -p.first;
    else if (d == 2) return -p.second;
    else if (d == 3) return p.first;
    return 0;
  }

  bool isSelfCrossing(vector<int>& x) {
    int prev[] = {3, 0, 1, 2};
    int next[] = {1, 2, 3, 0};
    pair<int, int> p(0, 0);
    int d = 0;
    int b[4] = {0, 0, 0, 0};
    bool is_outspread = true;
    int mid = 0;
    for (int i = 0; i != x.size(); ++i) {
      move(d, p, x[i]);
      if (is_outspread) {
        if (value(d, p) <= b[d]) {
          is_outspread = false;
          if (value(d, p) >= mid) {
            b[next[d]] = -b[prev[d]];
          }
        }
        mid = b[prev[d]];
        b[prev[d]] = value(prev[d], p);
      } else {
        if (value(d, p) >= b[d]) return true;
        b[prev[d]] = value(prev[d], p);
      }
      d = next[d];
    }
    return false;
  }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int p;
  vector<int> x;
  while (cin >> p) x.push_back(p);
  cout << Solution().isSelfCrossing(x);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
