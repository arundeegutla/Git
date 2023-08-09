#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr)
        x = nextInt();
    
    

    int prev = -1;
    vector<int> strip;
    for(auto x : arr){
        if(x == prev) continue;
        strip.push_back(x);
        prev = x;
    }

    if(strip.size() == 1){
        cout << "YES\n";
        return;
    }

    int count = (strip[1] > strip[0]) + (strip[strip.size()-2] > strip[strip.size()-1]);
    for(int i = 1; i+1 < strip.size(); i++)
        count += strip[i-1] > strip[i] && strip[i] < strip[i+1];
    cout << (count == 1 ? "YES\n" : "NO\n");

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}