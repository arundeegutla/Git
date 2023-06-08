#include <bits/stdc++.h>
using namespace std;


void solve() {
    string val; cin >> val;
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i < 3; i++)
        num1 += val[i]-'0';
    for(int i = 3; i < 6; i++)
        num2 += val[i]-'0';
    if(num1 == num2)
        cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}