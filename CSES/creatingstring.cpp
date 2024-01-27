#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> hset;
    int count = 0;
    do {
        count++;
        hset.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << count << "\n";
    for (auto x : hset) cout << x << "\n";
}