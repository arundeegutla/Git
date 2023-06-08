#include <bits/stdc++.h>
using namespace std;
#define long long long
int nextInt() {int a;cin >> a;return a;}
string next(){string a; cin >> a;return a;}
long nextLong(){long a; cin >> a;return a;}

void solve() {
    int n = nextInt();
    vector<int> a(n);
    vector<int> b(n);
    for(auto& x : a) x = nextInt();
    for(auto& x : b) x = nextInt();

    int prev = 0;
    int count = 0;
    vector<int> afreq((2*n) + 1, 0);
    for(int i = 0; i < n; i++){
        if(a[i] == prev){
            count++;
        } else {
            prev = a[i];
            count = 1;
        }
        afreq[a[i]] = max(count, afreq[a[i]]);
    }


    prev = 0;
    count = 0;
    vector<int> bfreq((2*n) + 1, 0);
    for(int i = 0; i < n; i++){
        if(b[i] == prev){
            count++;
        } else {
            prev = b[i];
            count = 1;
        }
        bfreq[b[i]] = max(count, bfreq[b[i]]);
    }

    int maxx = 0;

    for(int i = 1; i <= 2*n; i++)
        maxx = max(afreq[i]+bfreq[i], maxx);

    cout << maxx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = nextInt();
    while(n--) solve();
}