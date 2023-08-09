#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> strength(n);
    for(auto& x : strength) x = nextInt();

    // Want the maximum XOR subarray.
    unordered_set<int> pref;
    int num = 0;
    int maxx = 0;
    for(auto x : strength){
        pref.insert(num);
        num ^= x;
        // go thru all possible answers.
        // if i can remove a part of prefix from current prefix to make i.
        for(int i = (1<<8); i > maxx; i--)
            if(pref.find(num ^ i) != pref.end())
                maxx = i;
    }
    cout << maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}