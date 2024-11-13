// I went over the solution idea in detail in the discord.

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

string s;
int n;

int works[MAXN];

int countP() {
    int res = 0;

    for (int i = 0; i < n; i++)
        if (s[i] == 'P')
            res++;

    return res;
}

int simulate(int jump) {
    // Tests each starting point
    for (int start = 0; start < jump; start++) {
        int cur = start;

        // Gets all values in same set as "start"
        for (; cur < n; cur+=jump)
            if (s[cur] == 'P') // Invalid set
                break;

        // Valid path found!
        if (cur >= n)
            return true;
    }

    // No valid paths
    return false;
}

int solve() {
    int res = 0;

    int numP = countP(); // Counts the number of ponds

    // Test every jumpLength
    for (int jumpLength = 1; jumpLength < n; jumpLength++) {
        // The gcd of n and jumpLength also is the number of sets of positions
        // which can be landed on.
        int g = gcd(n, jumpLength);

        // If there are more sets than ponds, then there must be at least one set
        // which contains no ponds (pigeonhole principle (kind of)).
        if (numP < g)
            works[g] = 1;

        // Test g if not tested yet
        if (works[g] == -1) {
            works[g] = simulate(g);
        }

        res += works[g];
    }

    return res;
}

int main() {
    memset(works, -1, sizeof(works));

    cin >> s;
    n = int(s.length());

    cout << solve() << endl;
}