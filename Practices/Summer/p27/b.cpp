#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// Not TLE??
void solve() {

    int n = nextInt();
    int total = 0;
    vector<queue<int>> pq;

    for(int i = 0; i < n; i++){
        int m = nextInt();
        queue<int> q;
        for(int j = 0; j < m; j++){
            total++;
            q.push(nextInt());
        }
        pq.push_back(q);
    }


    
    int at = 0;
    vector<int> ans;
    while(at < total){
        sort(pq.begin(), pq.end());
        auto& a = pq[0];
        if(a.size()==0) {
            pq.erase(pq.begin());
            continue;
        }
        ans.push_back(a.front());a.pop();
        at++;
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i==ans.size()-1?"\n":" ");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}