#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {

    auto getScore = [&]() -> ll {
        ll T, F, S, P, C;
        cin >> T >> F >> S >> P >> C;

        ll tot = 0;
        tot += T*6;
        tot += F*3;
        tot += S*2;
        tot += P;
        tot += C*2;

        return tot;
    };

    int first = getScore();
    int second = getScore();
    cout << first << " " << second << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}