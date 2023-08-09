// #include <bits/stdc++.h>
// using namespace std;
// #define long long long
// int nextInt() {int a; cin >> a;return a;}
// long nextLong(){long a; cin >> a;return a;}
// string next(){string a; cin >> a;return a;}


#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt(){int a; cin >> a; return a;}
long nextLong(){long a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve(){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}

void solve() {
    int n = nextInt(), d = nextInt();
    
    vector<long> messAdd(n, 0);
    vector<long> canClean(n, 0);
    vector<bool> parent(n, false);
    for(int i = 0; i < n; i++){
        messAdd[i] = nextInt();
        canClean[i] = nextInt();
    }
    for(int i = 0; i < d; i++)
        parent[nextInt() - 1] = true;
    
    vector<vector<long>> memo(n+1, vector<long>(n+1, -1));

    auto go = [&](int at, int numCleans, auto && go) -> long {
        if(numCleans < 0) return (long)1e10;
        if(at == -1) return 0;
        long& ans = memo[at][numCleans];
        if(ans != -1) return ans;

        long cleaned = (go(at-1, numCleans-1, go) + messAdd[at]) - canClean[at];
        long dont = go(at-1, numCleans, go) + messAdd[at];

        ans = max(0LL, min(cleaned, dont));
        if(parent[at] && ans != 0)
            return ans = (long)1e10;

        return ans;
    };


    int ans = -1;
    int lo = 0;
    int hi = n;
    while(lo <= hi){
        int mid = (lo+hi) / 2;
        long thisAns = go(n-1, mid, go);
        if(thisAns < (long)1e9) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

}

