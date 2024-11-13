#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}


void solve() {
    int A = nextInt();
    int B = nextInt();
    int C = nextInt();
    ll k = nextLong();

    if(C - max(A, B) != 0 && C - max(A, B) != 1){
        cout << -1 << "\n";
        return;
    }

    // Going thru all A
    for(int a = pow(10, A-1); a < pow(10, A); a++){
        //         max:     low B  vs.  low C - a
        int left = max(pow(10, B-1), pow(10, C-1) - a);
        //         min:     high B  vs.  high C - a
        int right = min(pow(10, B)-1, pow(10, C) - 1 - a);
        if (left > right) continue;


        int possibles = right - left + 1;
        if (k <= possibles) {
            cout << a << " + " << left+k-1 << " = " << a+(left+k-1) << "\n";
            return;
        }
        k -= possibles;
    }

    cout << "-1" << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}