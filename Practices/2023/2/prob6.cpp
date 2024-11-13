#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    ll tot = 0;
    for(auto& x : arr){
        cin >> x;
        tot += x;
    }

    double minn = (arr[0]+arr[n-1])/(2.0);

    while()

    cout << fixed << setprecision(3) << minn << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}