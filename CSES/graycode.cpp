#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto getString = [&](int x) -> string {
        string s = bitset<30>(x).to_string();
        reverse(s.begin(), s.end());
        string news = s.substr(n);
        reverse(news.begin(), news.end());
        return news;
    };

    set<int> done;
    done.insert(0);
    cout << getString(0) << "\n";
    for (int i = 0; i < n; i++) {
        // fixing this bit
    }

    /*
        0000
        0001
        0011
        0111
        1111

    */
}