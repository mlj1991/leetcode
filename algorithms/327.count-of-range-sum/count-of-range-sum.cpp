#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>

using namespace std;

struct TreapNode {
  TreapNode *left, *right;
  int key, pri, son;

  TreapNode(int num) {
    left = NULL; right = NULL;
    key = num; pri = rand(); son = 1;
  }
};

void get_son(TreapNode*& i) {
  i->son = 1;
  if (i->left) i->son += i->left->son;
  if (i->right) i->son += i->right->son;
}

void left_rotate(TreapNode*& i) {
  TreapNode* j = i->right; i->right = j->left; j->left = i;
  get_son(i);
  get_son(j);
  i = j;
}

void right_rotate(TreapNode*& i) {
  TreapNode* j = i->left; i->left = j->right; j->right = i;
  get_son(i);
  get_son(j);
  i = j;
}

void insert(TreapNode*& i, int key) {
  if (i == NULL) i = new TreapNode(key);
  else if (key < i->key) {
    insert(i->left, key);
    i->son += 1;
    if (i->left->pri > i->pri) right_rotate(i);
  } else {
    insert(i->right, key);
    i->son += 1;
    if (i->right->pri > i->pri) left_rotate(i);
  }
}

int find_ranking(TreapNode*& i, long long key) {
  if (i == NULL) return 0;
  else if (key < i->key) {
    return find_ranking(i->left, key);
  } else {
    return (i->left?i->left->son:0) + 1 + find_ranking(i->right, key);
  }
}

class Solution {
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    srand(time(NULL));
    long long s = 0, ans = 0;
    TreapNode* root = NULL;
    insert(root, s);
    for (int i = 0; i != nums.size(); ++i) {
      s += nums[i];
      ans += find_ranking(root, s-lower) - find_ranking(root, s-upper-1);
      insert(root, s);
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  int lower, upper;
  int n;
  vector<int> nums;
  scanf("%d %d\n", &lower, &upper);
  scanf("%d\n", &n);
  for (int i = 0; i != n; ++i) {
    int k;
    scanf("%d", &k);
    nums.push_back(k);
  }
  printf("%d\n", Solution().countRangeSum(nums, lower, upper));
  fclose(stdin);
  fclose(stdout);
  return 0;
}
