#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int nextInt(){int a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve(vector<bool>& prime) {
    int n = nextInt();

    if(n==1){
        cout << "1\n";
        return;
    }

    if(n==2){
        cout << "1 2\n";
        return;
    }

    vector<int> ans(n);
    ans[n/2] = 1;
    ans[n-1] = 2;
    int at = 3;
    for(int i = 0; i < n; i++){
        if(ans[i] == 0)
            ans[i] = at++;
    }

    for(auto x : ans)
        cout << x << " ";
    cout << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int max = 1e5;
    vector<bool> prime(max+1, true);
    prime[1] = false;
    for (int i = 2; i * i <= max; i++)
        if (prime[i])
            for (int j = i * i; j <= max; j += i) 
                prime[j] = false;
    int n = nextInt();
    while(n--) solve(prime);
}