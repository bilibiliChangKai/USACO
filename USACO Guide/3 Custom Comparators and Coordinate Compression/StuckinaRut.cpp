#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Cow {
    int x;
    int y;
    int index;

    Cow() : x(0), y(0), index(0) {}
    Cow(int x, int y, int index) : x(x), y(y), index(index) {}
};


bool CompN(const Cow &left, const Cow &right) {
    return left.x < right.x;
}

bool CompE(const Cow &left, const Cow &right) {
    return left.y < right.y;
}

const int N = 1000;

int eCount = 0;
int nCount = 0;
int eCurrent = 0;
int nCurrent = 0;

Cow northCows[N];
Cow eastCows[N];
bool isRut[N];
int rutNum[N];

void CheckRutDiff(Cow &e, Cow &n) {
    if (e.x < n.x && e.y > n.y) {
        if (n.x - e.x < e.y - n.y) {
            // north rut
            isRut[n.index] = true;
            rutNum[e.index] += rutNum[n.index] + 1;

            // cout << "North Rut: " << n.index << " EaseIndex: " << e.index << " " << rutNum[e.index] << endl;
        }
        else if (n.x - e.x > e.y - n.y) {
            // east rut 
            isRut[e.index] = true;
            rutNum[n.index] += rutNum[e.index] + 1;

            // cout << "East Rut: " << e.index << " NorthIndex: " << n.index << " " << rutNum[n.index] << endl;
        }
    }
}

// east => x + 1
// north => y + 1
int main() {
    int n;
    cin >> n;
    getchar();
    

    int x, y;
    char direct;

    for (size_t i = 0; i < n; i++)
    {
        rutNum[i] = 0;
        isRut[i] = false;

        direct = getchar();
        cin >> x >> y;
        getchar();

        if (direct == 'E') {
            eastCows[eCount++] = Cow(x, y, i);
        }
        else {
            northCows[nCount++] = Cow(x, y, i);
        }
    }
    
    sort(eastCows, eastCows + eCount, CompE);
    sort(northCows, northCows + nCount, CompN);

    // for (int i = 0; i < eCount; i++) {
    //     cout << "E: " << eastCows[i].index << " " << eastCows[i].x << " " << eastCows[i].y << endl;
    // }

    // for (int i = 0; i < nCount; i++) {
    //     cout << "N: " << northCows[i].index << " " << northCows[i].x << " " << northCows[i].y << endl;
    // }

    for (int i = 0; i < eCount; i++) {
        for (int j = 0; j < nCount; ++j) {
            Cow &eP = eastCows[i];
            Cow &nP = northCows[j];
            
            if (!isRut[eP.index] && !isRut[nP.index]) {
                CheckRutDiff(eP, nP);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << rutNum[i] << endl;
    }
}