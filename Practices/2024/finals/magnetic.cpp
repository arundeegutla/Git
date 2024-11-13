#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846
int main() {
    int s, x, y;
    int S, X, Y;
    cin >> s >> x >> y >> S >> X >> Y;


    int pDist = (X - x) * (X - x) + (Y - y) * (Y - y);
    auto can = [&](double d) -> bool {
        double force = s / d;
        double Bforce = S / (pDist - d);
        
        return Bforce < force;
    };

    double lo = 0;
    double hi = pDist;
    double ans = -1;
    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if(can(mid)) {
            lo = mid;
            ans = mid;
        } else {
            hi = mid;
        }
    }

    cout << pi * ans << "\n";

}