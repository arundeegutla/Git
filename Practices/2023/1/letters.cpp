#include <bits/stdc++.h>
using namespace std;

int main(){
    int c = 1;
    while(true){
        string a, b;
        cin >> a >> b;
        if(a == "END" && b == "END") break;

        sort(begin(a), end(a));
        sort(begin(b), end(b));

        cout << "Case " << c << ": ";
        cout << (a==b? "same" : "different") << "\n";
        c++;
    }
}