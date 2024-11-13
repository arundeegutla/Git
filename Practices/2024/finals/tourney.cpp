#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // how many down.
    int numDown = (1 << n) - (m - 1);
    
    int rounds = 0;
    while (numDown > 1)
    {
        rounds++;
        numDown /= 2;
    }
        
    

    if(m != 1) {
        rounds++;
    }


    cout << rounds << "\n";
}