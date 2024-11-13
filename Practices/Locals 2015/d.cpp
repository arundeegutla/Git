#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int numDays, numLems, numSugarOunces;
        cin >> numDays >> numLems >> numSugarOunces;

        vector<int> numSold(numDays);
        vector<int> lemonPrice(numDays);
        vector<int> sugarPrice(numDays);

        for (int i = 0; i < numDays; i++) {
            cin >> numSold[i] >> lemonPrice[i] >> sugarPrice[i];
        }

        ll cost = 0;
        int curSugar = 0;
        int lowLemon = 1e9;
        int lowSugar = 1e9;
        for (int i = 0; i < numDays; i++) {
            lowLemon = min(lowLemon, lemonPrice[i]);
            lowSugar = min(lowSugar, sugarPrice[i]);

            int sold = numSold[i];
            int needLemons = numLems * sold;
            int sugarNeed = numSugarOunces * sold;

            cost += lowLemon * needLemons;

            while (curSugar < sugarNeed) {
                cost += lowSugar;
                curSugar += 5 * 16;
            }
            curSugar -= sugarNeed;
        }

        cout << cost << "\n";
    }
}