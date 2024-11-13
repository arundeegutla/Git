// This code gets real messy
// Could be done with segment tree and would prob be much cleaner
// (no invariants needing to be maintained).
// I thought of this problem essentially as a dp problem using maps to store
// the best possible cumulative donation amount for each beauty/fortune level
// given as input.

#include <bits/stdc++.h>
using namespace std;

int n;

using ll = long long;

int main() {
    cin >> n;
    
    // Store inputs <beauty, fortune, donation>
    vector<tuple<int, int, ll>> v(n);

    for (int i = 0; i < n; i++)
        cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);

    // The important thing with this line is that we want to process beauty
    // levels in non-decreasing order
    sort(v.begin(), v.end());

    // curMap: stores <fortune, donation> of processed ppl w/ same beauty
    // prevMap: stores <fortune, donation> of all ppl with lower beauty than cur person
    map<int, ll> curMap, prevMap;

    // Initial condition
    prevMap[0] = 0;
    curMap[0] = 0;

    // Used to determine if the beauty level changes btw ppl
    int b_prev = get<0>(v[0]);

    ll res = 0;

    // Process people in order
    for (int ii = 0; ii < n; ii++) {
        int b, f; ll d;
        tie(b, f, d) = v[ii];

        // Increase in beauty level
        if (b != b_prev) {
            b_prev = b; // Adjust beauty level
            
            // Insert all elements in curMap into prevMap
            for (auto it = curMap.begin(); it != curMap.end(); it++) {
                int ff; ll dd; tie(ff, dd) = *it;
                
                // Greatest donation in prev w/ fortune <= ff
                auto tmp = prevMap.upper_bound(ff);
                tmp--;

                int pff; ll pdd; tie(pff, pdd) = *tmp;

                // Map must maintain the following invariant:
                // If the fortune level of a pair is greater than another pair's, 
                // its donation level must be greater as well.
                // Formally: There cannot exist pairs i and j with fortune/donation levels
                // (f_i, d_i) and (f_j, d_j) s.t. f_i <= f_j && d_i >= d_j.
                if (pdd < dd) {
                    prevMap[ff] = dd;

                    // Also maintains previous invariant                    
                    auto itt = prevMap.upper_bound(ff);
                    while (itt != prevMap.end() && itt->second <= dd) {
                        int keyy = itt->first;
                        itt++;
                        prevMap.erase(keyy);
                    }
                }
            }

            // All elements have been inserted into prevMap
            curMap.clear();
            curMap[0] = 0;
        }

        // Max donation level for current beauty and fortune levels (b_cur, f_cur) 
        // is a donation level from one of the following 3 points (b_prev, f_prev):
        // 1. Maximal point prev where (b_prev < b_cur) && (f_prev < f_cur).
        // This case allows us to add donations from people with both beauty/fortune levels equal to cur.
        // 2. (b_prev < b_cur) && (f_prev == f_cur). This case presents a conflict of fortunes w/ prev and cur.
        // 3. (b_prev == b_cur) && (f_prev < f_cur). This case presents a conflict of beauties w/ prev and cur.
        
        ll cur = d + (--(prevMap.lower_bound(f)))->second;

        // Process potential duplicates (beauty and fortune level are the same)
        while ((ii+1 < n) && (get<0>(v[ii+1]) == get<0>(v[ii])) && (get<1>(v[ii+1]) == get<1>(v[ii])))
            cur += get<2>(v[++ii]);

        cur = max(cur, (--(prevMap.upper_bound(f)))->second);
        cur = max(cur, (--(curMap.lower_bound(f)))->second);

        curMap[f] = cur;

        res = max(res, cur);
    }

    cout << res << endl;
}