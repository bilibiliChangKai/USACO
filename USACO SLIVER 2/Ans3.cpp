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

long long f[300005];

void solve1() {
  string st;
  cin >> st;

  long long ans = 0;
  int n = st.size();

  int sz = 6;
  int first[10];
  for (int i = 1; i <= sz; i++) {
    first[i] = -1;
  }
  first[0] = 0;
  string tgt = "bessie";
  for (int i = 0; i < n; i++) {
    for (int c = sz - 1; c >= 1; c--) {
      if (st[i] == tgt[c] && first[c] >= first[c + 1]) {
        first[c + 1] = first[c];
      }
    }
    if (st[i] == tgt[0]) first[1] = i;
    
    cout << "index: " << i << endl;

    for (int i = 0; i <= sz; ++i) {
        cout << first[i] << " ";
    }
    cout << endl;

    if (first[sz] == -1) {
      f[i] = 0;
      continue;
    }
    int k = first[sz];
    f[i] = k + 1;
    if (k > 0) f[i] += f[k - 1];
    ans += f[i];
  }

  cout << ans << endl;
}

void solve2() {
  string st;
  cin >> st;

  long long ans = 0;
  int n = st.size();

  string tgt = "bessie";

  for (int k = 0; k < n; k++) {
    long long t = 0;
    int cur = 0;
    for (int i = k; i < n; i++) {
      if (st[i] == tgt[cur]) {
        cur++;
        if (cur == 6) {
          t++;
          cur = 0;
        }
      }
      ans += t;
    }
  }

  cout << ans << endl;
}

void Run() {
  // int T;
  // for (cin >> T; T; T--) solve1();
  solve1();
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

// 16
// besibesiesibe
// bessibessibessibessibessibessibessi
// bessssbbbssiessibessie
// bessiebessie
// abcdefghssijebessie
// bessibessie
// bebessiaabaaaessie
// bessiebebebessieie
// aaabessibessie
// aaabessbessie
// abcdefghssijebessie
// bessi