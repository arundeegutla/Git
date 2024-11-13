#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 5;
const int MAXC = 17;

int n;

bool good[1<<MAXC] = {false};
int nxt[MAXN][MAXC];

int main() {
    cin >> n;

    // Create a mask for each club group and mark as true.
    while (n--) {
        string s; cin >> s;

        int mask = 0;

        for (int i = 0; i < int(s.length()); i++)
            mask |= (1 << (s[i] - 'a'));

        good[mask] = true;
    }

    // If a mask has a club group as a subset, mark as true.
    for (int i = 0; i < (1 << MAXC); i++)
        if (good[i])
            for (int j = 0; j < MAXC; j++)
                good[i|(1<<j)] = true;

    // Schedule
    string sch; cin >> sch;
    int len = int(sch.length());
    
    // Keeps track of the indexes of the last 
    // seen instance of character ('a' + i).
    vector<int> lastSeen(MAXC, MAXN);

    // Update nxt[i][j] with the index of the closest 
    // character of type ('a' + j) to the right of index 'i'.
    for (int i = len-1; i >= 0; i--) {
        for (int j = 0; j < MAXC; j++)
            nxt[i][j] = lastSeen[j];

        lastSeen[sch[i] - 'a'] = i; 
    }

    ll res = 0;

    // For each starting point 'i' in sch, find the closest end point 
    // such that the substring between 'i' and 'cur' inclusive contains
    // all members of a club at least once (we can do this greedily by visiting
    // the index of the closest character we havent seen yet until we get a valid mask).
    for (int i = 0; i < len; i++) {
        // Starting point and mask.
        int cur = i;
        int mask = (1 << (sch[i] - 'a'));

        // Loop until we find the shortest valid substring.
        while ((cur < len) && (!good[mask])) {
            int to = MAXN; // Index of closest character not yet seen.

            // Find the index of the closest character not yet seen.
            for (int j = 0; j < MAXC; j++) 
                if (!(mask & (1 << j)))
                    to = min(to, nxt[cur][j]);
            
            // Update current index.
            cur = to;

            // Break if out of bounds.
            if (cur >= len)
                break;

            // Update mask.
            mask |= (1 << (sch[cur] - 'a'));
        }

        // If the substring [l, r] is good, the substring [l, r+x] is also good
        // (assuming x is a positive integer and r+x < n). Count all of those substrings.
        res += max(len - cur, 0);
    }
    
    // Answer.
    cout << res << endl;
}