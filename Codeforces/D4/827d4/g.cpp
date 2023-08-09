#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define int ll
void solve() {
    int n = nextInt();
    vector<ll> arr;
    for(int i = 0; i < n; i++)
        arr.push_back(nextInt());

    ll finalXOR = 0;
    for(auto k : arr) finalXOR |= k;
    
    sort(arr.begin(), arr.end());

    vector<bool> used(n);
    vector<ll> ans;
    int at = 30;
    ll cur = 0;
    while(cur != finalXOR) {
        if(!(finalXOR & (1LL<<at)) || (cur & (1LL<<at))) {
            at--;
            continue;
        }
        
        ll leftneed = (1LL<<at);
        ll rightNeed = (1LL<<(at+1))-1;

        int lo = 0;
        int hi = n-1;
        int leftInd = 0;
        while(lo <= hi){
            int mid = (lo+hi) >> 1;
            if(arr[mid] >= leftneed) {
                hi = (leftInd = mid) - 1;
            } else 
                lo = mid + 1;
        }

        lo = 0;
        hi = n-1;
        int rightInd = -1;
        while(lo <= hi){
            int mid = (lo+hi) >> 1;
            if(arr[mid] <= rightNeed) {
                lo = (rightInd = mid) + 1;
            } else 
                hi = mid - 1;
        }

        int ind = -1;
        int maxx = cur;
        for(int i = leftInd; i <= rightInd; i++){
            if(!used[i] && ((cur|arr[i]) > maxx)){
                maxx = cur|arr[i];
                ind = i;
            }
        }

        used[ind] = true;
        ans.push_back(arr[ind]);
        cur = maxx;
        at--;
    }

    for(int i = 0; i < n; i++)
        if(!used[i])    
            ans.push_back(arr[i]);

    for(auto x : ans) 
        cout << x << " ";
    cout << '\n';
    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}
