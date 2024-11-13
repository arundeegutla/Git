#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_set<char> hset;
    for(auto& x : s) hset.insert(x);
    cout << hset.size() - 1 << "\n"; 
}