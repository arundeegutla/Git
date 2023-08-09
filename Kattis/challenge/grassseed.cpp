#include <bits/stdc++.h>
using namespace std;
#define double long double
double nextDouble(){double a; cin >> a; return a;}
int main(){
    double c = (nextDouble() * 1e8);
    int l; cin >> l;
    double sum = 0;
    while(l--){
        double w = nextDouble();
        double l = nextDouble();
        sum += (c*l*w)/1e8;
    } 
    cout << sum << "\n";

}
