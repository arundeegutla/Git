#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    
    queue<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push(x);
    }

    queue<int> b;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b.push(x);
    }

    while(b.size()){
        int curB = b.front(); b.pop();
        while(a.size() && a.front() < curB) a.pop();
        cout << n - a.size() << " ";
    }

    cout << "\n";

}