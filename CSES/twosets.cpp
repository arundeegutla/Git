#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll tot = (n * (n + 1)) / 2;
    if (tot % 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    set<int> a;
    set<int> b;
    if (n % 2) {
        for (int i = 1; i <= n / 2; i += 2) {
            a.insert(i);
        }
        for (int i = 2; i <= n / 2; i += 2) {
            b.insert(i);
        }
        for (int i = n - 1; i >= n / 2; i -= 2) {
            a.insert(i);
        }
        for (int i = n - 2; i > n / 2; i -= 2) {
            b.insert(i);
        }
        if (n % 2) {
            b.insert(n);
        }
    } else {
        for (int i = 1; i < n / 2; i += 2) {
            a.insert(i);
        }
        for (int i = 2; i <= n / 2; i += 2) {
            b.insert(i);
        }
        for (int i = n; i > n / 2; i -= 2) {
            a.insert(i);
        }
        for (int i = n - 1; i >= n / 2; i -= 2) {
            b.insert(i);
        }
    }

    cout << a.size() << "\n";
    for (auto x : a) cout << x << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for (auto x : b) cout << x << " ";
    cout << "\n";
}