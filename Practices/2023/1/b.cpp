#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    map<int, int> V;
    map<int, int> H;
    map<int, int> P;
    map<int, int> N;

    map<pair<int, int>, int> VH;
    map<pair<int, int>, int> VP;
    map<pair<int, int>, int> VN;

    map<pair<int, int>, int> HP;
    map<pair<int, int>, int> HN;
    map<pair<int, int>, int> PN;

    map<pair<int, pair<int, int>>, int> VHP;
    map<pair<int, pair<int, int>>, int> VHN;
    map<pair<int, pair<int, int>>, int> VPN;
    map<pair<int, pair<int, int>>, int> HPN;

    int n; 
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        int h, v, p, n;

        h = y;
        v = x;
        p = x+y;
        n = x-y;

        V[v]++; 
        H[h]++; 
        P[p]++;
        N[n]++;

        VH[{v, h}]++;
        VP[{v, p}]++;
        VN[{v, n}]++;

        HP[{h, p}]++;
        HN[{h, n}]++;

        PN[{p, n}]++;

        VHP[{v, {h, p}}]++;
        VHN[{v, {h, n}}]++;
        VPN[{v, {p, n}}]++;
        HPN[{h, {p, n}}]++;
    }   


    
    for(auto [v, countV] : V){
        for(auto [h, countH] : H){
            for(auto [p, countP] : P){

                ll tot = countV + countH + countP;


                tot -= VH[{v, h}];
                tot -= VP[{v, p}];
                tot -= HP[{h, p}];
                tot += VHP[{v, {h, p}}];

                if(tot == n) {
                    cout << "possible" << "\n";
                    return 0;
                }
            }
        }
    }

    for(auto [v, countV] : V){
        for(auto [h, countH] : H){
            for(auto [n, countN] : N){

                ll tot = countV + countH + countN;
                tot -= VH[{v, h}];
                tot -= VN[{v, n}];
                tot -= HN[{h, n}];
                tot += VHN[{v, {h, n}}];
                
                if(tot == n) {
                    cout << "possible" << "\n";
                    return 0;
                }
            }
        }
    }

    for(auto [v, countV] : V){
        for(auto [p, countP] : H){
            for(auto [n, countN] : N){

                ll tot = countV + countP + countN;
                tot -= VP[{v, p}];
                tot -= VN[{v, n}];
                tot -= PN[{p, n}];
                tot += VPN[{v, {p, n}}];
                
                if(tot == n) {
                    cout << "possible" << "\n";
                    return 0;
                }
            }
        }
    }


    for(auto [h, countH] : H){
        for(auto [p, countP] : H){
            for(auto [n, countN] : N){

                ll tot = countH + countP + countN;
                tot -= HP[{h, p}];
                tot -= HN[{h, n}];
                tot -= PN[{p, n}];
                tot += HPN[{h, {p, n}}];
                
                if(tot == n) {
                    cout << "possible" << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "impossible" << "\n";

}