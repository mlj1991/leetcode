#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
private:
  const static int stepx[];
  const static int stepy[];
  int ans;
  int n;
  int m;
  int** d;

public:
  int dfs(int x, int y, const vector< vector<int> >& matrix) {
    if (d[x][y]) return d[x][y];

    d[x][y] = 1;
    for (int i = 0; i != 4; ++i) {
      int xx = x+stepx[i];
      int yy = y+stepy[i];
      if (xx >= 0 && xx <= n-1 && yy >= 0 && yy <= m-1 && matrix[xx][yy] > matrix[x][y]) {
        int k = dfs(xx, yy, matrix);
        if (k+1 > d[x][y]) d[x][y] = k+1;
      }
    }
    return d[x][y];
  }

  int longestIncreasingPath(vector< vector<int> >& matrix) {
    ans = 0;
    n = matrix.size();
    m = 0;
    if (n) m = matrix[0].size();
    d = new int*[n];
    for (int i = 0; i != n; ++i) {
      d[i] = new int[m];
      memset(d[i], 0, m*sizeof(int));
    }

    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) {
        int k = dfs(i, j, matrix);
        if (k > ans) ans = k;
      }
    }

    for (int i = 0; i != n; ++i) {
      delete[] d[i];
    }
    delete[] d;
    return ans;
  }
};

const int Solution::stepx[] = {-1, 0, 1, 0};
const int Solution::stepy[] = {0, -1, 0, 1};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int n, m;
  vector< vector<int> > matrix;
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i != n; ++i) {
    vector<int> row;
    for (int j = 0; j != n; ++j) {
      int k;
      scanf("%d", &k);
      row.push_back(k);
    }
    matrix.push_back(row);
  }
  cout << Solution().longestIncreasingPath(matrix);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
