// Didnt finish
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll one = nextLong();
    ll two = nextLong();
    if(two > one) swap(one, two);

    if(!(one%two)) {
        cout << "win\n";
        return;
    }

    if((one%2) && (two%2)) {
        cout << "win\n";
        return;
    }

    if(!(one%2) && !(two%2)) {
        cout << "lose\n";
        return;
    }

    if((one/two) >= 2) {
        cout << "win\n";
        return;
    }

    cout << "lose\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}