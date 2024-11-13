#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> a;
    while(n--){
        int x; cin >> x;
        a.push(x);
    }
    queue<int> b;
    while(m--){
        int x; cin >> x;
        b.push(x);
    }

    ll tot = 0;
    ll prev = -1e10;
    while(a.size()){
        ll val = a.front();
        ll count = 0;
        while(a.size() && a.front()==val){
            count++;
            a.pop();
        }
        ll countB = 0;
        while(b.size() && b.front() <= val){
            countB += b.front() == val;
            b.pop();
        }
        tot += countB * count;
    }
    cout << tot << "\n";
}