#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n + 1);
    v[0] = 0;

    long long temp;
    long long maxValue = 0;
    long long minValue = 0;
    long long answer = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        v[i] = v[i - 1] + temp;

        minValue = min(minValue, v[i - 1]);
        answer = max(answer, v[i] - minValue);
    }

    cout << answer << endl;
    return 0;
}