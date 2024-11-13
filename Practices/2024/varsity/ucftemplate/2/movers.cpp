#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> cts(n), extra(n);
    for(int i = 0; i < n; i++)
    {
        int desks;
        cin >> desks;
        cts[i] = desks;
    }
    for(int i = 0; i < n; i++)
    {
        int monitors;
        cin >> monitors;
        cts[i] -= monitors;
    }
    vector<unordered_set<int>> g(n);
    for(int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    int cutoff = sqrt(n);
    unordered_set<int> large;
    for(int i = 0; i < n; i++)
    {
        if(g[i].size() >= cutoff)
            large.insert(i);
    }
    for(int i = 0; i < n; i++)
    {
        for(auto l : large)
        {
            if(g[i].count(l))
                extra[l] += cts[i];
        }
    }

    for(int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if(op[0] == 'c') // check
        {
            int lab;
            cin >> lab;
            lab--;
            int res = cts[lab];
            if(large.count(lab))
                res += extra[lab];
            else
            {
                for(int l : g[lab])
                    res += cts[l];
            }

            if(res > 0)
                cout << "desks\n";
            else if(res < 0)
                cout << "monitors\n";
            else
                cout << "same\n";
        }
        else // add
        {
            string type;
            int ct, lab;
            cin >> ct >> type >> lab;
            lab--;
            // desks or monitors
            if(type[0] != 'd')
                ct = -ct;
            cts[lab] += ct;
            for(auto l : large)
            {
                if(g[lab].count(l))
                    extra[l] += ct;
            }
        }
    }

    return 0;
}
