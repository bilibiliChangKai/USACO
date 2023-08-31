#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 150010;
const int MAXM = 1 << 19;
int n, c, a[MAXN], ones[MAXM], ans[MAXM];
bool f[MAXM];
vector<int> ones_num[22];

void solve() {
  cin >> c >> n;
  ones[0] = 0;
  int m = 1 << c;
  for (int i = 1; i < m; i++) {
    ones[i] = ones[i & (i - 1)] + 1;
  }

  for (int i = 0; i < n; i++) {
    string st;
    cin >> st;
    int t = 0;
    for (int j = 0; j < c; j++) {
      t <<= 1;
      if (st[j] == 'G') t++;
    }
    a[i] = t;
    f[a[i]] = 1;
    ans[i] = 0;
  }

  if (n <= 8000) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int t = ones[a[i] ^ a[j]];
        if (t > ans[i]) ans[i] = t;
        if (t > ans[j]) ans[j] = t;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
    return;
  }

  for (int i = 0; i < m; i++) {
    ones_num[ones[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    int t = a[i];
    bool ok = false;
    if (ans[t] != 0) {
      cout << ans[t] << endl;
      continue;
    }
    for (int j = c; j >= 0; j--) {
      for (auto k : ones_num[j]) {
        if (f[t ^ k]) {
          ans[t] = j;
          cout << j << endl;
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
  }
}

void Run() {
  // int T;
  // for (cin >> T; T; T--) solve();
  solve();
}

int main(int argc, char *argv[]) {
#ifdef ALGO_TESTRUN
  if (argc >= 3) {
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  Run();
}