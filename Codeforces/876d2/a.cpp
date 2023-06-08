#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();
    int l = 1;
    int r = n;
    int sum = 0;
    int count = 0;
    while(l < r){
        if(count < ceil((double)l/k))
            count++;
        l++;
        r--;
    }
    cout << (count*2)+(n%k!=0) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}