#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> KMP(string& s) {
    vector<int> pre(s.size());
    pre[0] = -1;
    for (int j = 1; j != s.size(); ++j) {
      int k = pre[j-1];
      while (k != -1 && s[k+1] != s[j]) k = pre[k];
      if (s[k+1] == s[j]) pre[j] = k+1;
      else pre[j] = -1;
    }
    return pre;
  }

  vector< vector<int> > palindromePairs(vector<string>& words) {
    vector< vector<int> > ans;
    unordered_map<string, int> words_index;
    for (int i = 0; i != words.size(); ++i) {
      words_index[words[i]] = i;
    }

    for (int i = 0; i != words.size(); ++i) {
      string word_r = words[i];
      reverse(word_r.begin(), word_r.end());
      string s = word_r + "$" + words[i];
      vector<int> pre = KMP(s);
      int j = pre.size()-1;
      while (j != -1) {
        string w = s.substr(pre[j]+1, words[i].size()-pre[j]-1);
        if (words_index.count(w) && i != words_index[w]) {
          vector<int> item;
          item.push_back(i);
          item.push_back(words_index[w]);
          ans.push_back(item);
        }
        j = pre[j];
      }
      s = words[i] + "$" + word_r;
      pre = KMP(s);
      j = pre.size()-1;
      while (pre[j] != -1) {
        string w = s.substr(words[i].size()+1, words[i].size()-pre[j]-1);
        if (words_index.count(w)) {
          vector<int> item;
          item.push_back(words_index[w]);
          item.push_back(i);
          ans.push_back(item);
        }
        j = pre[j];
      }
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  string s;
  vector<string> words;
  while (getline(cin, s)) words.push_back(s);
  vector< vector<int> > ans = Solution().palindromePairs(words);
  for (int i = 0; i != ans.size(); ++i) {
    cout << ans[i][0] << ' ' << ans[i][1] << endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
