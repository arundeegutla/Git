#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();

    vector<int> a(n);
    vector<int> b(n);

    for(auto& x : a) x = nextInt();
    for(auto& x : b) x = nextInt();
    
    unordered_map<int, queue<int>> hmap;
    for(int i = 0; i < n; i++)
        hmap[a[i]].push(i);
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int ind = hmap[a[i]].front(); hmap[a[i]].pop();
        ans[ind] = b[i];
    }

    for(auto x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}