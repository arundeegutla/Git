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


ll tsp(vector<vector<ll>>& dist){
    int n = dist.size();
    int ALL = (1<<n) - 1;
    vector<vector<ll>> memo(n, vector<ll>(1<<n, -1));
    auto help = [&](int cur, int seen, auto&& help) -> ll {
         auto& ans = memo[cur][seen];    
         if(ans!=-1) return ans;
         if (seen == ALL) return dist[cur][0];
         ll minn = 1e9;
         for (int i = 0; i < n; i++)
             if (!(seen & (1<<i)))
                minn = min(minn, help(i, (seen|(1<<i)), help) + dist[cur][i]);
         return ans = minn;
    };
    ll shortest = 1e9;
    for (int i = 0; i < n; i++){
        ll thisShortest = help(i, 1<<i, help) + dist[0][i];   
        shortest = min(shortest, thisShortest);
    }
    return shortest;
}


int main() {
    
    

    string s;
    cin >> s;
    vi arr;
    for(auto x : s) arr.push_back(x - 'a' + 1);

    SuffixArray sa(arr);

    int k;
    cin >> k;

    while(k--){
        string check; 
        cin >> check;

        int lo = 1;
        int hi = s.size();
        bool found = 0;
        while(lo <= hi) {
            int mid = (lo+hi) >> 1;
            int cmp = -1;

            for(int i = 0, j = sa.sa[mid]; i < check.size() && j < s.size(); i++, j++){
                if(s[j] > check[i]){
                    cmp = 1;
                    break;
                } else if(s[j] < check[i]) {
                    cmp = -1;
                    break;
                }
                if(i==check.size()-1){
                    cmp = 0;
                    break;
                }
            }

            if(cmp == 0) {
                found = true;
                break;
            } else if(cmp > 0) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << (found ? "Yes" : "No") << "\n";

    }

}


int getFactors(ll product) {
    set<ll> factors;
    for (ll i = 1; i*i <= product; i++) {
        if (product%i == 0) {
            factors.insert(product/i);
            factors.insert(i);
        }
    }
    factors.insert(product);
    return factors.size();
}