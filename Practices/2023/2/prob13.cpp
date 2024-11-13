#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int q;
    cin >> q;
    vector<ll> sum(2e5);
    vector<int> parent(2e5, -1);
    unordered_map<string, int> id;

    auto update = [&](int at, ll val, auto&& update) -> void {
        if(at == -1) return;
        sum[at] += val;
        update(parent[at], val, update);
    };

    while(q--){
        string type;
        cin >> type;

        if(type == "ADD"){
            string par, name;
            cin >> par >> name;
            id[name] = id.size();
            if(par != "ROOT") parent[id[name]] = id[par];
            
        } else if(type == "SALE"){
            string emp;
            ll x;
            cin >> emp >> x;
            update(id[emp], x, update);
        } else {
            string name;
            cin >> name;
            cout << sum[id[name]] << "\n";
        }


    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "COMPANY " << i << "\n";
        solve();
    }
}