#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

void solve(){
    string f, t; cin >> f >> t;

    ll from = stoll(f, nullptr, 16);
    ll to = stoll(t, nullptr, 16);


    auto equal = [](ll a, ll b) -> bool {
        return bitset<32>(a).to_string() == bitset<32>(b).to_string();
    };

    ll leftFrom = from;
    int left = 0;
    while(!equal(leftFrom, to) && left <= 40){
        bool add = (leftFrom & (1LL<<31));
        leftFrom <<= 1LL;
        leftFrom |= add;
        left++;
    }

    ll rightFrom = from;
    int right = 0;
    while(!equal(rightFrom, to) && right <= 40){
        bool add = (rightFrom & 1LL);
        rightFrom >>= 1LL;
        if(add) rightFrom |= (1LL<<31);
        right++;
    }

    if(equal(rightFrom, to) && equal(leftFrom, to)){
        if(left == right){
            cout << left << " Any\n";
            return;
        } 
        if(left < right){
            cout << left << " Left\n";
            return;
        }
        cout << right << " Right\n";
        return;
    }

    cout << "Not possible" << '\n';
    
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}