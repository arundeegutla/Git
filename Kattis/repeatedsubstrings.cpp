#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)

struct SuffixArray{
    vi sa, lcp;
    SuffixArray(vi &s, int lim = 256){
        int n = s.size() + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
        x.back() = 0;
        sa = lcp = y, iota(all(sa), 0);
        for(int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p){
            p = j, iota(all(y), n - j);
            for(int i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for(int i = 0; i < n; i++) ws[x[i]]++;
            for(int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for(int i = n; i--; ) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for(int i = 1; i < n; i++) a = sa[i - 1], b = sa[i], x[b] = 
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for(int i = 1; i < n; i++) rank[sa[i]] = i;
        for(int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for(k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};


void solve(){
    string s; 
    cin >> s;
    
    vi arr;
    for(auto x : s)
        arr.push_back(x);

    SuffixArray sa(arr);

    ll n = s.size();

    ll ans = sa.lcp[1];
    for(int i = 2; i <= n; i++){
        ans += (sa.lcp[i] > sa.lcp[i-1] ? sa.lcp[i] - sa.lcp[i-1] : 0);
    }

    cout << ans << "\n";
    
}

int main(){
    int n; cin >> n;
    while(n--) solve();
}