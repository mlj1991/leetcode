#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

template <class T>
int getArrayLen(T& array)
{
  return (sizeof(array) / sizeof(array[0]));
}

const char vowels[] = {'a', 'o', 'e', 'u', 'i'};

class Solution {
private:
  vector<int> vowels_index;

public:
  string reverseVowels(string s) {
      for (int i = 0; i != s.size(); ++i) {
        for (int j = 0; j != getArrayLen(vowels); ++j) {
          if (tolower(s[i]) == vowels[j]) {
            vowels_index.push_back(i);
            break;
          }
        }
      }
      for (int i = 0; i != vowels_index.size()/2; ++i) {
        int x = vowels_index[i];
        int y = vowels_index[vowels_index.size() - i - 1];
        char k = s[x]; s[x] = s[y]; s[y] = k;
      }
      return s;
    }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  string s;
  cin >> s;
  cout << Solution().reverseVowels(s);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
