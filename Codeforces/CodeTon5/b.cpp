#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), x = nextInt();
    vector<ll> first;
    vector<ll> second;
    vector<ll> third;

    int have = 0;
    bool found = x==0;
    bool skip = false;
    for(int i = 0; i < n; i++) {
        int num = nextInt();
        if(skip) continue;
        if((x|num) == x) have |= num;
        else skip = true;
        if(have == x) found = true;
    }
    skip = false;
    for(int i = 0; i < n; i++) {
        int num = nextInt();
        if(skip) continue;
        if((x|num) == x) have |= num;
        else skip = true;
        if(have == x) found = true;
    }
    skip = false;
    for(int i = 0; i < n; i++) {
        int num = nextInt();
        if(skip) continue;
        if((x|num) == x)
            have |= num;
        else
            skip = true;
        if(have == x) found = true;
    }

    cout << (found ? "YES" : "NO") << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}