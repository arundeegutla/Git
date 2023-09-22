#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    priority_queue<ll> pq;
    for(int i = 0; i < 10; i++){
        cout << "i: " << i << "\n";
    }
    while(pq.size()){
        cout << pq.top() << "\n";
        pq.pop();
    } 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}