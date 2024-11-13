#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    getline(cin, s);

    stringstream sin(s);

    unordered_map<string, int> id;
    while (sin.good()) {
        string name;
        sin >> name;
        id[name] = id.size();
    }

    vector<unordered_set<int>> eats(id.size());

    int n;
    cin >> n;

    while (n--) {
        string a, t, b;
        cin >> a >> t >> b;
        eats[id[a]].insert(id[b]);
    }

    vector<int> memo(1 << (id.size() + 1), -1);

    function<int(int)> go;
    go = [&](int taken) -> int {
        if (bitset<20>(taken).count() == id.size()) return 0;
        auto& ans = memo[taken];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        vector<int> nextMasks;
        auto getmasks = [&](int at, int mask, auto&& getmasks) -> void {
            if (at == id.size()) {
                if (bitset<20>(mask).count() >= 1)
                    nextMasks.push_back(mask);
                return;
            }
            getmasks(at + 1, mask, getmasks);
            if ((taken & (1 << at)) == 0) {
                getmasks(at + 1, mask | (1 << at), getmasks);
            }
        };
        getmasks(0, 0, getmasks);

        int minn = 1e18;
        for (auto mask : nextMasks) {
            vector<int> taking;
            for (int i = 0; i < id.size(); i++)
                if ((mask & (1 << i)) != 0)
                    taking.push_back(i);

            bool works = true;
            for (auto x : taking)
                for (auto y : taking)
                    works &= eats[x].find(y) == eats[x].end();
            if (!works) continue;

            minn = min(minn, go(taken | mask) + 1);
        }

        return ans = minn;
    };

    cout << go(0) << "\n";
}