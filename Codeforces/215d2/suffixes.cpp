#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}

void solve() {
    int n = nextInt(), m = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    int count = 0;
    vector<bool> seen((int)1e5 + 1);
    vector<int> sum(n);
    for(int i = n-1; i >= 0; i--){
        sum[i] = count += !seen[arr[i]];
        seen[arr[i]] = true;
    }

    while(m--)
        cout << sum[nextInt() - 1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}