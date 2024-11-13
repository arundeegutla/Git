#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements
ll findlcm(vector<int> arr) {
    int n = arr.size();
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
               (gcd(arr[i], ans)));

    return ans;
}
int main() {
    cout << findlcm({99, 100, 101}) << "\n";
}