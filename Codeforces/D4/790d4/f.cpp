#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int k = nextInt();
    int maxx = 0;
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());
    
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        int at = arr[i];
        int start = at, end = -1;
        while(at <= maxx){
            int count = 0;
            while (i < n && arr[i] == at) {
                i++;
                count++;
            }
            if(count < k) break;
            end = at;
            if(i < n && arr[i] == at+1) at++;
        }
        i--;
        if(end != -1 && (l == -1 || (end - start) > (r-l))) {
            l = start;
            r = end;
        }
    }
    if(l==-1) cout << -1 << "\n";
    else cout << l << " " << r << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}