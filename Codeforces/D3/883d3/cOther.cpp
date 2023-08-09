#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool comp(pair<ll, pair<ll, ll>>& a, pair<ll, pair<ll, ll>>& b) {
    if(a.first == b.first)
        if(a.second.first == b.second.first) 
            return (a.second.second == 1);

    if(a.first == b.first)
        return (a.second.first < b.second.first);
    return (a.first > b.first);
}

void solve()
{
    ll n, m, h; cin >> n >> m >> h;
    vector<vector<int>> a(n, vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    vector<pair<ll, pair<ll, ll>>> b(n);

    for(int i=0;i<n;i++){
        int cnt = 0;
        int time = 0;
        int penalty = 0;
        for(int j=0;j<m;j++){
            if(time+a[i][j] <= h){
                cnt++;
                time += a[i][j];
                penalty += time;
            }else break;
        }
        b[i] = {cnt, {penalty, i+1}};
    }

    sort(b.begin(), b.end(), comp);

    for(int i=0;i<n;i++)
        if(b[i].second.second == 1) 
            cout << i+1 << endl;
    return;
}

int main()
{
    ll n; cin >> n;
    while (n--) solve();
    return 0;
}
