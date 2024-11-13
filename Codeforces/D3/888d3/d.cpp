#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextInt();
    vector<ll> arr(n-1);
    for(auto& x : arr) x = nextLong();



    map<ll, int> have;
    have[arr[0]]++;
    for(int i = 0; i+1 < n-1; i++){
        have[arr[i+1] - arr[i]]++;
    }


    set<int> missing;
    for(int i = 1; i <= n; i++)
        if(have.find(i) == have.end())
            missing.insert(i);

    if(missing.size() == 0 || missing.size() > 2){
        cout << "NO\n";
        return;
    }
    if(missing.size() == 1){
        cout << "YES\n";
        return;
    }

    int num1 = -1;
    int num2 = -1;
    for(auto x : missing)
        if(num1 == -1)
            num1 = x;
        else    
            num2 = x;

    if(have[num1+num2] == 0){
        cout << "NO\n";
        return;
    }


    have[num1]++;
    have[num2]++;
    have[num1+num2]--;

    for(int i = 1; i <= n; i++)
        if(!have[i]){

            cout << "NO\n";
            return;
        }
    
    cout << "YES" << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}