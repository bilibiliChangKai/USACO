#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>

using namespace std;

const int N = 100000;

string str;
int pokemonNums[256];

int main() {
    int n;
    cin >> n;
    
    cin >> str;

    memset(pokemonNums, 0, sizeof(pokemonNums));

    int typeNums = 0;
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (pokemonNums[c] == 0) {
            pokemonNums[c] = 1;
            ++typeNums;
        }
    }

    memset(pokemonNums, 0, sizeof(pokemonNums));

    int left = 0;
    int right = 0;

    int currentNums = 0;;
    int minStep = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (pokemonNums[c] == 0) {
            currentNums++;
        }

        pokemonNums[c]++;

        if (currentNums == typeNums) {
            right = i;
            char leftC = str[left];
            if (pokemonNums[leftC] > 1) {
                for (; left < right; ++left) {
                    leftC = str[left];
                    if (pokemonNums[leftC] <= 1) {
                        break;
                    }

                    pokemonNums[str[left]]--;
                }
            }

            minStep = min(minStep, right - left + 1);
        }
    }

    cout << minStep << endl;
}
    