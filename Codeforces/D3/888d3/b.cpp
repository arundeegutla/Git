#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();

    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();

    vector<ll> sorted = arr;
    sort(sorted.begin(), sorted.end());

    map<int, queue<int>> ind;
    for(int i = 0; i < n; i++)
        ind[sorted[i]].push(i);

    for(int i = 0; i < n; i++){
        while(true){
            if(!ind[arr[i]].size()) break;
            int x = ind[arr[i]].front(); ind[arr[i]].pop(); 
            if(x == i) break;
            if(arr[x]%2 == arr[i]%2){
                swap(arr[x], arr[i]);
            } else {
                break;
            }

        }
    }
    
    cout << (arr==sorted ? "YES\n" : "NO\n");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}