#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, p;
    cin >> n >> p;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;

    vector<ll> psum(n+1);
    for(int i = 0; i < n; i++)
        psum[i+1] = psum[i] + arr[i];

    ll start = -1;
    ll listen = LLONG_MAX;
    for(int i = 0; i < n; i++){

        ll tot = 0;
        ll curP = p;
        ll allRun = curP/psum[n];
        tot += n * allRun;
        curP -= psum[n] * allRun;


        ll nextSongsSum = psum[n] - psum[i];

        // cout << i+1 << " " << curP << " " << nextSongsSum << " " << tot << "\n";


        if(curP >= nextSongsSum) {
            curP -= nextSongsSum;
            tot += n - i;
            int lo = 0;
            int hi = i;
            int ans = -1;
            while(lo <= hi) {
                int mid = (lo+hi) >> 1;
                if(psum[mid] >= curP) {
                    hi = (ans = mid) - 1;
                } else {
                    lo = mid + 1;
                }
            }
            tot += ans;
        } else if(curP > 0){

            int lo = i+1;
            int hi = n;
            int ans = -1;
            while(lo <= hi) {
                int mid = (lo+hi) >> 1;
                if(psum[mid] - psum[i] >= curP) {
                    hi = (ans = mid) - 1;
                } else {
                    lo = mid + 1;
                }
            }
            curP -= psum[ans] - psum[i];
            tot += ans-i;
        }


        if(tot < listen){
            listen = tot;
            start = i+1;
        }
    }

    cout << start << " " << listen << "\n";
}