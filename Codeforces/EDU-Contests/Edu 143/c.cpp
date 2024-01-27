#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<ll> tea(n);
    vector<ll> tester(n);
    for(auto& x : tea) x = nextInt();
    for(auto& x : tester) x = nextInt();

    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + tester[i-1];

    auto get = [&](ll need) -> int {
        int ans = -1;
        int lo = 1;
        int hi = n;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(prefix[mid] <= need)
                lo = (ans = mid) + 1;
            else 
                hi = mid - 1;
        }
        return ans-1;
    };

    vector<ll> count(n+1);
    vector<ll> remaining(n+1);
    for(int i = 0; i < n; i++){
        int finishIndex = get(prefix[i] + tea[i]);
        cout << finishIndex << "::\n";
        count[i]++;
        count[finishIndex+1]--;
        remaining[finishIndex+1] += tea[i] - (prefix[finishIndex+1] - prefix[i]);
    }

    vector<ll> tot(n);
    int c = 0;
    for(int i = 0; i < n; i++){
        c += count[i];
        tot[i] = (tester[i] * c) + remaining[i];
    }

    for(auto x : tot)
        cout << x << " ";
    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}