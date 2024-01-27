#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (auto& [e, s] : movies) {
        cin >> s >> e;
    }
    sort(movies.begin(), movies.end());
    pair<int, int> prevMovie = {-1, -1};
    int tot = 0;
    for (auto& [e, s] : movies) {
        if (prevMovie.second <= s) {
            tot++;
            prevMovie = {s, e};
        }
    }

    cout << tot << "\n";
}