#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    int maxx = -1;
    int ind = -1;
    for(int i=1; i <= n; i++){
        int num = nextInt();
        int q = nextInt();
        if(maxx < q && num <= 10){
            maxx = q;
            ind = i;
        }
    }
    cout << ind << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}