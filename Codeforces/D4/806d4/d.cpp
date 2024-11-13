#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<string> arr(n);
    for(auto& x : arr) x = next();


    set<string> hset;
    for(auto x : arr)
        hset.insert(x);

    string ans;
    for(auto x : arr){
        bool done = false;
        for(int i = 0; i+1 < x.size(); i++){
            if(hset.find(x.substr(0, i+1)) != hset.end() && hset.find(x.substr(i+1, x.size())) != hset.end()){
                ans.push_back('1');
                done = true;
                break;
            }
        }
        if(!done) ans.push_back('0');
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}