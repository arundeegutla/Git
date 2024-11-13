#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

vector<bool> prime(1e7+1, true);




void solve() {
    ll l, r; cin >> l >> r;
    int higherEven = r-2 - ((r-2)%2);
    if(higherEven > 0 && higherEven+2 >= l && higherEven+2 <= r){
        cout << higherEven << " " << 2 << "\n";
        return;
    }

    if(higherEven <= 0 || prime[l]) {
        cout << -1 << "\n";
        return;
    }

    assert(l == r);
    for(int i = 2; i*2 <= l; i++){
        if(!((l-i) % i)){
            cout << l-i << " " << i << "\n";
            return;
        }
    }

    cout <<  -1 << "\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for (int i = 2; i * i <= 1e7+1; i++)
        if (prime[i])
            for (int j = i * i; j <= 1e7+1; j += i) 
                prime[j] = false;

    int n; cin >> n;
    while(n--) solve();
}