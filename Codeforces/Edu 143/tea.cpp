#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCases;
    cin >> numCases;
    const int maxN = 2e5;
    vector<int> amount(maxN);
    vector<int> tasters(maxN);
    vector<long long> totals(maxN);
    while (numCases--) {
        int numTotal;
        cin >> numTotal;
        
        for (int i = 0; i < numTotal; i++) 
            cin >> amount[i];

        for (int i = 0; i < numTotal; i++)
            cin >> tasters[i];

        for (int i = 0; i < numTotal; i++) {
            totals[i] = 0;
            for (int j = i; j >= 0; j--) {
                totals[i] += min(tasters[i], amount[j]);
                amount[j] -= min(tasters[i], amount[j]);
            }
        }
        for (int i = 0; i < numTotal; i++) {
            cout << totals[i] << (i == numTotal - 1 ? "\n" : " ");
        }
    }
    return 0;
}
