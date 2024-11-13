#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve()
{
    int n;
    cin >> n;

    unordered_map<string, int> freq;

    try {
        while (cin.good()) {
            string s;
            cin >> s;
            if (s[0] == '#') {
                string x = s.substr(1, s.size()-1-(s[s.size()-1] == '.'));
                for(auto& c : x){
                    c = tolower(c);
                }
                freq[x]++;
            }
        }
    }
    catch (const std::exception &e) {}

    set<pair<int, string>> order;
    for (auto [k, v] : freq)
        order.insert({-v, k});

    for (auto [v, name] : order)
        cout << -v << " " << name << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}