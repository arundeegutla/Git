#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    double tot = 0;
    while(n--){
        double h = nextInt();
        double w = nextInt();
        h /= 2.0;
        w /= 2.0;
        double c = sqrt(h*h+w*w);
        tot += 3.14159265358979323846264338327950288*c*c;
    }

    cout << fixed << setprecision(10) << tot << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}