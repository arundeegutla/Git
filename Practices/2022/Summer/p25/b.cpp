#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> nums(n);
    for(auto& x : nums) x = nextInt();
    int start = nums[0];
    for(int i = 0; i < n; i++){
        int cur = start + i;
        
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}