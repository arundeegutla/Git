#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();

    map<int, set<int>> ind;
    for(int i = 1; i <= n; i++){
        int num = nextInt();
        if(num%k==0){
            ind[k].insert(i);
        } else {
            ind[num%k].insert(i);
        }
    }

    vector<int> ans;
    for(auto& [k, v] : ind){
        vector<int> my;
        for(auto i : v){
            my.push_back(i);
        }
        reverse(my.begin(), my.end());
        for(auto x : my)    
            ans.push_back(x);
    }

    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << " ";
    }
    cout <<  "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}