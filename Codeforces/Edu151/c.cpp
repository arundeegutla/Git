#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define oo (int)1e9
void solve() {
    string database = next();
    vector<set<int>> inds(10);
    for(int i = 0; i < database.size(); i++)
        inds[database[i]-'0'].insert(i);

    int len = nextInt();
    string l = next();
    string r = next();

    int at = -1;
    for(int i = 0; i < len; i++){
        int maxx = i;
        for(int num = l[i]-'0'; num <= r[i]-'0'; num++){
            auto dex = inds[num].upper_bound(at);
            if(dex == inds[num].end()){
                maxx = oo;
            } else {
                maxx = max(maxx, *(dex));
            }
        }
        at = maxx;
    }

    cout << (at == oo ? "YES" : "NO") << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}