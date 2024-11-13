#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    string s;
    cin >> s;
    reverse(all(s));
    double power = 3.0/2.0;
    double value = 0;
    int i = 0;
    for(auto x : s) {
        value += (x-'0') * (pow(power, i));
        i++;
    }

    int num = value;
    value -= num;
    if(value == 0) {
        cout << num << "\n";
        return;
    }

    value *= 1e9;
    int mgcd = gcd((int)value, (int)1e9);
    int numerator = value/mgcd;
    int denom = 1e9/mgcd;

    cout << num << " " << numerator<< "/" << denom << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}