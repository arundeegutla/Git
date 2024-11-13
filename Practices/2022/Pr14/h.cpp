#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int getMin(int i, int k, vector<int> &arr, unordered_map<int, unordered_map<int, int>> map) {

    if (i == 0 && k == 0)
        return 0;

    if (i == 0 || k < 0)
        return 1e9;

    if(map[i][k] != 0)
        return map[i][k];

    int ans = min(getMin(i-1, k, arr, map), 1 + getMin(i-1, k-arr[i], arr, map));

    map[i][k] = ans;

    return ans;
}

int getMinHelp(int at, int need, vector<int> &arr) {
    unordered_map<int, unordered_map<int, int>> map;
    return getMin(at, need, arr, map);
}

int main() {
    int LOWEST = 1e9;

    int maxHots = 0;
    int numHots;
    cin >> numHots;
    vector<int> hotdogs(numHots);
    for (int i = 0; i < hotdogs.size(); i++){
        cin >> hotdogs[i];
        maxHots += hotdogs[i];
    }

    int maxBuns = 0;
    int numBuns;
    cin >> numBuns;
    vector<int> buns(numBuns);
    for (int i = 0; i < buns.size(); i++) {
        cin >> buns[i];
        maxBuns += buns[i];
    }

    int minNum = min(maxBuns, maxHots);

    for (int i = 1; i <= minNum ; i++)
        LOWEST = min(getMinHelp(hotdogs.size() - 1, i, hotdogs), getMinHelp(buns.size() - 1, i, buns));

    if (LOWEST >= 1e9) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << LOWEST << endl;
}



