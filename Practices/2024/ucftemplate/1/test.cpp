#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, string>> arr;
    while (cin.good()) {
        string s;
        getline(cin, s, ',');
        stringstream sin(s);

        string first, last;
        sin >> first >> last;

        arr.push_back({last, first});
    }

    sort(arr.begin(), arr.end());

    for (auto x : arr) cout << x.second << " " << x.first << ", ";
}