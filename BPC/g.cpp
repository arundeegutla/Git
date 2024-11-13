#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, t;
    cin >> n >> t;

    auto parse = [&](string s) -> pair<string, string> {
        s.pop_back();
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());

        stringstream sin(s);
        vector<string> info;
        string name, qt;
        getline(sin, name, ',');
        getline(sin, qt, ',');
        return {name, qt};
    };

    unordered_map<string, int> inventory;
    while (n--) {
        string s;
        cin >> s;
        auto here = parse(s);
        inventory[here.first] = stoll(here.second);
    }
    string temp;
    getline(cin, temp);

    string s;
    int tot = 0;

    while (t--) {
        string line;
        getline(cin, line);
        stringstream sin1(line);
        string itemInfo;
        string items;
        getline(sin1, itemInfo, ':');
        getline(sin1, items, ':');
        auto infoPair = parse(itemInfo);

        bool can = true;
        stringstream sin2(items);
        while (sin2.good()) {
            string s;
            sin2 >> s;
            auto info = parse(s);
            can &= inventory[info.first] >= stoll(info.second);
        }

        if (can) {
            s += infoPair.second[0];
            tot += stoll(infoPair.first);
        }
    }

    cout << s << "\n";
    cout << tot << "\n";
}