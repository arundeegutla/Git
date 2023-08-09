#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}


void solve() {

    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    map<int, int> ind;
    for(int i = n - 1; i >= 0; i--)
        if(ind[arr[i]]==0)
            ind[arr[i]]=i+1;

    int maxx = -1;
    for(auto [a, i] : ind)
        for(auto [b, j] : ind)
            if(gcd(a, b) == 1)
                maxx = max(maxx, i + j);
    cout << maxx << "\n";
}

int main(){
    // int n = 1000;
    // vector<bool> prime(1001, true);
    // prime[0] = false;
    // for (int i = 2; i * i <= n; i++)
    //     if (prime[i])
    //         for (int j = i * i; j <= n; j += i) 
    //             prime[j] = false;

    // int count = 0;
    // for(auto x : prime)
    //     count += x;
    // cout << count << "\n";

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int x = nextInt();
    while(x--) solve();
}