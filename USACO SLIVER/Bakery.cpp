#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define f first
#define s second
#define Pair pair<int, int>

struct Friend {
public:
    long long a;
    long long b;
    long long c;
};

vector<Friend> friendList;

inline bool BinarySearch(long long x, long long y, long long reduce) {
    long long lx = max(1ll, x - reduce);
    long long hx = min(x, x + y - reduce - 1);
    
    for (auto &&i : friendList)
    {
        long long a = i.a;
        long long b = i.b;
        long long c = i.c;
        long long d = x + y - reduce;

        if (b - a > 0) {
            lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
        }
        else if (a - b > 0) {
            hx = min(hx, (c - b * d) / (a - b));
        }
        else {
            if (c < b * d) {
                return false;
            }
        }
    }
    
    return lx <= hx;
}

void solve() {
    int n;
    long long x, y;

    cin >> n >> x >> y;

    friendList.clear();

    long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        friendList.push_back({a, b, c});
    }


    long long count = x + y - 2;
    long long left = 0;
    long long right = count;

    while (left < right) {
        long long mid = (left + right) / 2;
        bool ans = BinarySearch(x, y, mid);

        if (ans) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}

int main() {
    int caseNum;

    cin >> caseNum;

    for (int i = 0; i < caseNum; i++)
    {
        solve();
    }
}