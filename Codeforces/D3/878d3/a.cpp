#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int len = nextInt();
    string a = next();
    int i = 0;
    while(i < len){
        char c = a[i];
        cout << c;
        i++;
        while(i < len && a[i] != c)
            i++;
        i++;
        
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}