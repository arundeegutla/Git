#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    vector<int> ind(n + 1, n + 100);
    for (int i = 0; i < n; i++) {
        ind[arr[i]] = i;
    }

    int rounds = 0;
    for (int i = 1; i <= n; i++) {
        rounds += ind[i] < ind[i - 1];
    }

    while (m--) {
        int indA, indB;
        cin >> indA >> indB;
        indA--, indB--;

        int valA = arr[indA];
        int valB = arr[indB];

        unordered_set<int> check;
        check.insert(valA);
        check.insert(valA - 1);
        check.insert(valB);
        check.insert(valB - 1);

        for (auto x : check) {
            if (x + 1 <= n)
                rounds -= ind[x + 1] < ind[x];
        }

        arr[indA] = valB;
        arr[indB] = valA;
        ind[valA] = indB;
        ind[valB] = indA;

        for (auto x : check) {
            if (x + 1 <= n)
                rounds += ind[x + 1] < ind[x];
        }

        cout << rounds << "\n";
    }
}