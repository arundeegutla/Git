#include <bits/stdc++.h>
using namespace std;

void solve(){

    auto distance = [](pair<double, double> pt, pair<double, double> other) -> double {
        double px = pt.first - other.first;
        double py = pt.second - other.second;
        return sqrt(px * px + py * py);
    };

    int m; cin >> m;
    double diameter; cin >> diameter;
    diameter /= 2;
    vector<pair<double, double>> masquitoes(m);

    for(auto& x : masquitoes)
        cin >> x.first >> x.second;
    
    int maxx = 0;

    for(int i = -100; i <= 100; i++){
        for(int j = -100; j <= 100; j++){
            int count = 0;
            for(auto x : masquitoes){
                count += distance(make_pair(i))
            }
        }
    }
    
    cout << maxx << "\n";
}

int main(){
    int n; cin>>n;
    while(n--)solve();
}