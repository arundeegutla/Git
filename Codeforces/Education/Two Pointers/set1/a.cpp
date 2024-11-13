#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> a;
    queue<int> b;
    while(n--){
        int x; cin >> x;
        a.push(x);
    }
    while(m--){
        int x; cin >> x;
        b.push(x);
    }


    while(a.size() || b.size()){
        if(a.size() && b.size()){
            if(a.front() <= b.front()){
                cout << a.front() << " ";
                a.pop();
            } else {
                cout << b.front() << " ";
                b.pop();
            }
        } else if(a.size()){
            cout << a.front() << " ";
            a.pop();
        } else {
            cout << b.front() << " ";
            b.pop();
        }
    }

}