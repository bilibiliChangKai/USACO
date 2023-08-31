#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define Point pair<int, int> 

bool compare(Point p1, Point p2) {
    return p1.second < p2.second;
}

inline int CaculateRectSum(vector<vector<int> > &v, int minX, int minY, int maxX, int maxY) {
    return v[maxX][maxY] - v[maxX][minY - 1] - v[minX - 1][maxY] + v[minX - 1][minY - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        p[i].first = i + 1;
    }
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < n; i++) {
        p[i].second = i + 1;
    }

    vector<vector<int> > v(n + 1);
    // reset
    for (int i = 0; i < n + 1; ++i) {
        v[i].resize(n + 1);
    }

    for (int i = 0; i < n; i++) {
        v[p[i].first][p[i].second] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }


    // cout << "Matrix:" << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << v[i][j] << ' ';
    //     }

    //     cout << endl;
    // }

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; ++j) {
            Point &p1 = p[i];
            Point &p2 = p[j];

            int minX = min(p1.first, p2.first);
            int maxX = max(p1.first, p2.first);
            int minY = p1.second;
            int maxY = p2.second;

            //cout << "minX: " << minX << ", maxX: " << maxX << ", minY: " << minY << ", maxY: " << maxY << endl;

            int left = CaculateRectSum(v, minX, 1, maxX, minY);
            int right = CaculateRectSum(v, minX, maxY, maxX, n);

            //cout << "Left: " << left << ", right: " << right << endl;
            answer += left * right; 
        }
    }

    cout << answer + 1 << endl;

    return 0;
}