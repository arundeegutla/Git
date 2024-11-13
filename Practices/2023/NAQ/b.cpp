#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sort(digits.begin(), digits.end(), [](string a, string b) -> bool {
        return a.size() > b.size();
    });

    ll MOD = 9302023L;
    vector<pair<int, ll>> memoShort(n, {-1, -1});
    function<pair<int, ll>(int)> shortest;
    shortest = [&](int at) -> pair<int, ll> {
        if (at >= n) return {0, 1};
        auto& ans = memoShort[at];
        if (ans.first != -1) {
            return ans;
        }

        pair<int, ll> minn = shortest(at + 1);
        minn.first += 1;
        for (int i = 0; i < digits.size(); i++) {
            int x = 0, y = 0;
            bool valid = true;
            while (y < digits[i].size()) {
                if (x + at < n)
                    valid &= digits[i][y] == s[x + at];
                else
                    valid = false;
                x++;
                y++;
            }

            if (!valid) continue;
            auto here = shortest(at + digits[i].size());
            if (here.first == minn.first) {
                minn.second += here.second;
                minn.second %= MOD;
            } else {
                if (minn.first > here.first)
                    minn = here;
            }
        }
        return ans = minn;
    };

    auto ans = shortest(0);
    cout << ans.first << "\n";
    cout << ans.second << "\n";
}