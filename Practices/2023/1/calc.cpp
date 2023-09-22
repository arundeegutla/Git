#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    while(n--){
        int start;
        cin >> start;

        unordered_map<int, int> dist;
        queue<ll> q;
        q.push(start);
        dist[start] = 0;
    
        while(q.size()){

            ll cur = q.front();q.pop();
            ll d = dist[cur];

            if(cur > 1e3) continue;

            ll add = cur+1;
            ll mult = cur*3;
            ll div = cur/2;

            if(dist.find(add) == dist.end() || dist[add] > d + 1){
                dist[add] = d+1;
                q.push(add);
            }

            if(dist.find(mult) == dist.end() || dist[mult] > d + 1){
                dist[mult] = d+1;
                q.push(mult);
            }

            if(dist.find(div) == dist.end() || dist[div] > d + 1){
                dist[div] = d+1;
                q.push(div);
            }

        }


        int maxx = 0;
        for(int i = 1; i <= 99; i++){
            maxx = max(dist[i], maxx);
        }

        cout << maxx << "\n";
    }
}