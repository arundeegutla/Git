#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    vector<bool> memo(1e5);
    function<int(int, int)> go;
    go = [&](int at, int sum) -> int {
        if (at == n) return 0;

        int take = go(at + 1, sum + arr[at])
    };
}
