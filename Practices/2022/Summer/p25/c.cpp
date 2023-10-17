#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve() {
    int len = nextInt();
    if(!(len % 2)) {
        cout << "NOT POSSIBLE" << "\n";
        return;
    }

    string u; cin >> u;
    string firstHalf = u.substr(0, len/2);
    string secondHalf = u.substr(len/2+1);

    bool removedA = false;
    bool matchedB = false;
    for(int i = 0; i <= len/2; i++){
        if(u[i] != secondHalf[i - removedA]) {
            if(removedA) break;
            removedA = true;
        }
        if(i - removedA == (len/2) - 1){
            matchedB = true;
            break;
        }
    }

    bool removedB = false;
    bool matchedA = false;
    for(int i = len/2; i < len; i++){
        if(u[i] != firstHalf[i - len/2 - removedB]) {
            if(removedB) break;
            removedB = true;
        }
        if(i - len/2 - removedB == (len/2) - 1){
            matchedA = true;
            break;
        }
    }

    if(matchedA && matchedB && (firstHalf != secondHalf)) 
        cout << "NOT UNIQUE" << "\n";
    else if (matchedA) 
        cout << firstHalf << "\n";
    else if (matchedB) 
        cout << secondHalf << "\n";
    else 
        cout << "NOT POSSIBLE" << "\n";



}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
