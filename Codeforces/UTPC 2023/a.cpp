#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
using ll = long long;

template<class T, class U> istream& operator >> (istream &is, pair<T, U>& p) { 
    is >> p.first >> p.second; 
    return is; 
}
template<class T> istream& operator >> (istream& is, vector<T>& vec) { 
    for(auto &x : vec) 
        cin >> x; 
    return is; 
} 
template<class T, class U> ostream& operator << (ostream &os, pair<T, U>& p) { 
    os << "<" << p.first << "," << p.second << ">"; 
    return os; 
}
template<class T> ostream& operator << (ostream& os, vector<T>& vec) { 
    for(auto x : vec) 
        os << x << " "; 
    return os; 
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vi> arr(n, vi(n));
    cin >> arr;
    while (q--) {
        int l, r; cin >> l >> r;
        int j = n-1;
        int res = 1;
        for (int i = 0; i < n; i++) {
            while (j>0 && arr[i][j] > r) j--;
            while (res <= i && res <= j && arr[i-res][j-res] >= l) res++;
        }
        cout << res*res << "\n";
    }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << fixed << setprecision(10);
    solve();
	return 0;
}