#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<int> arr(n);
    for(auto& x : arr) x = nextInt();

    map<int, int> hmap;
    int c = 0;
    for(auto x : arr){
        hmap[x]++;
        if(hmap[x] > hmap[c])
            c = x;
    }

    vector<int> color(arr);
    for(auto& x : color){
        if(x == c){
            x = 1;
        } else {
            x = -1;
        }
    }


    ll sum = 0;
    ll maxx = 0;
    pair<int, int> range = {0, 0};
    int s = 0;
    for(int i = 0; i < n; i++){
        sum += color[i];
        if(maxx < sum){
            maxx = sum;
            range = {s, i};
        }
        if(sum < 0){
            sum = 0;
            s = i+1;
        }
    }

    cout << c << " " << range.first+1 << " " << range.second+1 <<'\n';

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}