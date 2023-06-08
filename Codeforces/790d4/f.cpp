#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k; cin >> n >> k;
    int maxx = 0;
    map<int, int> map;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        map[num]++;
        maxx = max(maxx, num);
    }

    int l = -1, r = -1;
    int start = 0;
    while(true) {
        auto s = map.upper_bound(start);

        while(s != map.end() && (*s).second < k)
            s = map.upper_bound((*s).first);

        if(s == map.end())
            break;
        
        start = (*s).first;
        int end = start;

        while(map[end] >= k)
            end++;
        end--;
        if(l==-1 || (end - start) > (r-l)){
            l = start;
            r = end;
        }
        start = end+1;
    }

    if(l==-1){
        cout << -1 << "\n";
    } else {
        cout << l << " " << r << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
}