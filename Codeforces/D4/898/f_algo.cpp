#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll query(int l, int r, vector<ll> &par){
    ll big = par[r];
    if(l) big-=par[l-1];
    return big;
}
ll maxfruits;
bool good(int mid, int start, vector<ll> &heights, vector<ll> &div){
    if(start+mid-1 >= heights.size()) return false;
   // cout << mid << " " << start << "\n";
    int left = start;
    int right = start+mid-1;
    if(query(left,right,heights) > maxfruits) return false;
    int numdiv = query(left,right,div);
    if(numdiv == (right-left+1) || (numdiv == (right-left) && query(right,right,div) == 0) ){
        return true;
    }else{
        return false;
    }
   // cout << "returned true\n";
    return true;


}

void solve(){
    int n,k; cin >> n >> k; maxfruits = k;
    vector<ll> vals(n); for(auto &x: vals) cin >> x;
    vector<ll> heights(n); for(auto &x: heights) cin >> x;
    vector<ll> valsp(n);
    vector<ll> divis(n);
    vector<ll> divisp(n);
    for(int i = 0; i < n; i++){
        if(i+1 != n && ((heights[i]%heights[i+1]) == 0)){
            divis[i] = 1;
        }else{
            divis[i] = 0;
        }
    }
  
    partial_sum(divis.begin(),divis.end(),divisp.begin());
    partial_sum(vals.begin(),vals.end(),valsp.begin());
   // for(auto d: divis) cout << d << " "; cout << "\n";
    //for(auto v: vals) cout << v << " "; cout << "\n";
//
    ll best = 0;
    for(int start = 0; start < n; start++){
        //if(divis[start] == 0) continue;
        if(vals[start] > k) continue;
        ll lo = 1; ll hi = 1e6; ll mid;
        while(lo!=hi){
            mid = lo+(hi-lo+1)/2;
            if(good(mid,start,valsp,divisp)) lo = mid;
            else hi = mid-1;
        }
        cout << best << " " << lo << "\n";
        best = max(best,lo);
    }

    cout << best << "\n";



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases; cin >> cases;
    while(cases--) solve();


    return 0;
}