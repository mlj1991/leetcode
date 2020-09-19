#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

struct Info {
  int circle;
  int index;
  int d;
};

class BlackBox {
private:
  int n;
  int m;
  unordered_map<int, Info> map_info_;
  vector< map<int, int> > vec_circle_;
  vector< map<int, int> > vec_circle2_;
  vector<bool> is_circle_;

  int get_num(int x, int y) {
    if (x == 0) {
      return n+m+m+y;
    }
    if (x == m) {
      return n+m-y;
    }
    if (y == 0) {
      return n+m+m-x;
    }
    if (y == n) {
      return x;
    }
    return -1;
  }

  void get_next(int &num, int &d) {
    int x = 0;
    int y = 0;
    if (num < m) {
      x = num;
      y = n;
      if (d == 1) {
        int p = min(x, y);
        x -= p;
        y -= p;
      } else {
        int p = min(m-x, y);
        x += p;
        y -= p;
      }
    } else if (num < n+m) {
      x = m;
      y = (n+m)-num;
      if (d ==1) {
        int p = min(x, y);
        x -= p;
        y -= p;
      } else {
        int p = min(x, n-y);
        x -= p;
        y += p;
      }
    } else if (num < n+m+m) {
      x = (n+m+m)-num;
      y = 0;
      if (d == 1) {
        int p = min(m-x, n-y);
        x += p;
        y += p;
      } else {
        int p = min(x, n-y);
        x -= p;
        y += p;
      }
    } else {
      x = 0;
      y = num-(n+m+m);
      if (d == 1) {
        int p = min(m-x, n-y);
        x += p;
        y += p;
      } else {
        int p = min(m-x, y);
        x += p;
        y -= p;
      }
    }
    d = -d;
    num = get_num(x, y);
  }

  void find_circle(int num, int d) {
    if (map_info_.find(num) != map_info_.end()) {
      return;
    }

    map<int, int> root;
    vec_circle_.push_back(root);
    vec_circle2_.push_back(root);
    int circle = vec_circle_.size()-1;
    int index = 0;
    int now = num;

    Info info;
    info.circle = circle;
    info.index = index;
    info.d = d;
    map_info_[now] = info;

    //cout << circle << ": ";
    //cout << now << "," << d << " ";
    while (1) {
      get_next(now, d);
      if (now == num) {
        is_circle_.push_back(true);
        break;
      }
      index++;
      //cout << now << "," << d << " ";

      Info info;
      info.circle = circle;
      info.index = index;
      info.d = d;
      map_info_[now] = info;

      if (now == 0 || now == m || now == n+m || now == n+m+m) {
        is_circle_.push_back(false);
        break;
      }
    }
    //cout << endl;
  }

  void init() {
    find_circle(0, -1);
    find_circle(n+m, -1);
    find_circle(m, 1);
    find_circle(n+m+m, 1);
    for (int i = 0; i != (n+m)*2; i++) {
      find_circle(i, 1);
    }
  }

public:
  BlackBox(int n, int m) {
    this->n = n;
    this->m = m;
    init();
  }

  int open(int index, int direction) {
    int c = map_info_[index].circle;
    int i = map_info_[index].index;
    int d = map_info_[index].d;
    map<int, int> &circle(vec_circle_[c]);
    map<int, int> &circle2(vec_circle2_[c]);
    circle[i] = index;
    circle2[-i] = index;
    bool upper = true;
    if (direction != d) {
      upper = false;
    }
    
    map<int, int>::iterator iter;
    if (upper) {
      iter = circle.upper_bound(i);
      if (iter != circle.end()) {
        return iter->second;
      }
      if (is_circle_[c]) {
        return circle.upper_bound(-1)->second;
      }
      return index;
    } else {
      iter = circle2.upper_bound(-i);
      if (iter != circle2.end()) {
        return iter->second;
      }
      if (is_circle_[c]) {
        return circle2.upper_bound(-(n+n+m+m))->second;
      }
      return index;
    }
  }

  void close(int index) {
    int c = map_info_[index].circle;
    int i = map_info_[index].index;
    vec_circle_[c].erase(vec_circle_[c].find(i));
    vec_circle2_[c].erase(vec_circle2_[c].find(-i));
  }
};

int main() {
  //Your BlackBox object will be instantiated and called as such:
  //int n = 2;
  //int m = 3;
  //BlackBox* obj = new BlackBox(n, m);
  //cout << obj->open(6, -1) << endl;
  //cout << obj->open(4, -1) << endl;
  //cout << obj->open(0, -1) << endl;
  //obj->close(6);
  //cout << obj->open(0, -1) << endl;
  int n = 3;
  int m = 3;
  BlackBox* obj = new BlackBox(n, m);
  cout << obj->open(1, -1) << endl;
  cout << obj->open(5, 1) << endl;
  cout << obj->open(11, -1) << endl;
  cout << obj->open(11, 1) << endl;
  obj->close(1);
  cout << obj->open(11, 1) << endl;
  obj->close(5);
  cout << obj->open(11, -1) << endl;
} 
