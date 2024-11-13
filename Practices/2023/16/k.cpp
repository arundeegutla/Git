#include <bits/stdc++.h>
using namespace std;

int main() {
    string temp;
    getline(cin, temp);

    string s;
    for (auto& c : temp) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            s += toupper(c);
        }
    }
    unordered_map<char, int> freq;
    for (auto c : s) {
        freq[c]++;
    }

    unordered_map<string, int> codes;
    auto go = [&](string x, int price, auto&& go) -> void {
        if (price > 30) return;
        if (price > 0) codes[x] = price;
        // put dot
        string temp = x;
        temp += '.';
        int bet = temp.size() > 1;
        go(temp, price + 1 + bet, go);
        // put dash
        temp = x;
        temp += '-';
        bet = temp.size() > 1;
        go(temp, price + 3 + bet, go);
    };
    go("", 0, go);

    vector<pair<int, string>> codesArr;
    for (auto [k, v] : codes)
        codesArr.push_back({v, k});
    sort(codesArr.begin(), codesArr.end());

    // for (auto [k, v] : codesArr) {
    //     cout << v << ": " << k << "\n";
    // }
    int tot = (s.size() - 1) * 3;

    vector<pair<int, char>> arr;
    for (auto [k, v] : freq)
        arr.push_back({v, k});
    sort(arr.begin(), arr.end(), greater<pair<int, char>>());

    int at = 0;
    for (auto [v, k] : arr) {
        tot += codesArr[at].first * v;
        at++;
    }

    cout << tot << "\n";
}