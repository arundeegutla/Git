#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define x first
#define y second
void solve() {
    pair<int, int> k;
    pair<int, int> K;
    pair<int, int> R;

    for(int i = 0; i < 8; i++){
        string row = next();
        for(int j = 0; j < 8; j++){
            if(row[j] == 'k') k = {i, j};
            if(row[j] == 'K') K = {i, j};
            if(row[j] == 'R') R = {i, j};
        }
    }

    if(R.x == k.x && K.x == k.x && ((K.y < k.y && K.y > R.y) || (K.y > k.y && K.y < R.y))) {
        cout << "No" << "\n";
        return;
    }

    if(R.y == k.y && K.y == k.y && ((K.x < k.x && K.x > R.x) || (K.x > k.x && K.x < R.x))) {
        cout << "No" << "\n";
        return;
    }


    if(R.y == k.y && K.y == k.y && ((K.x < k.x && K.x > R.x) || (K.x > k.x && K.x < R.x))) {
        cout << "No" << "\n";
        return;
    }

    if(abs(k.y-K.y)+abs(k.x-K.x) > 1) {

    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}