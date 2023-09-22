#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();

    map<int, set<int>> hmap;
    for(int i = 0; i < n; i++){
        int own = nextInt();
        int rating = nextInt();
        hmap[own].insert(rating);
    }

    int maxx = 0;
    for(auto [k, v] : hmap){
        if(*(v.begin()) <= maxx){
            cout << "yes\n";
            return;
        }
        maxx = max(maxx, *(max_element(all(v))));
        
    }

    cout << "no\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}