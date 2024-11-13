#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using S = array<pii, 2>;

struct DSU
{
    vector<int> p, ct;
    DSU(int n) : p(n), ct(n, 1)
    {
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int k)
    {
        if(p[k] == k)
            return k;
        return p[k] = find(p[k]);
    }

    bool merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a == b)
            return true;

        if(ct[a] > ct[b])
            swap(a,b);

        p[a] = b;
        ct[b] += ct[a];
        return false;
    }
};

// y is fixed
bool isHorizontal(S seg)
{
    return seg[0].second == seg[1].second;
}

// move y (working with normal coords!)
S above(S seg)
{
    seg[0].second++;
    seg[1].second++;
    return seg;
}
S below(S seg)
{
    seg[0].second--;
    seg[1].second--;
    return seg;
}
// move x
S left(S seg)
{
    seg[0].first--;
    seg[1].first--;
    return seg;
}
S right(S seg)
{
    seg[0].first++;
    seg[1].first++;
    return seg;
}

int main()
{
    int n;
    cin >> n;

    vector<array<pii, 2>> segs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> segs[i][0].first >> segs[i][0].second;
        cin >> segs[i][1].first >> segs[i][1].second;
        if (segs[i][0] > segs[i][1])
            swap(segs[i][0], segs[i][1]);
    }

    // coordinate compress
    map<pii, int> pts;
    int o = 0;
    for(auto seg : segs)
    {
        for(auto p : seg)
        {
            if(!pts.count(p))
                pts[p] = o++;
        }
    }
    DSU dsu(pts.size());
    for(auto [p1, p2] : segs)
    {
        // must be closing a loop if they are already linked
        if(dsu.merge(pts[p1], pts[p2]))
        {
            cout << 0;
            return 0;
        }
    }

    sort(segs.begin(), segs.end());
    auto exists = [&](S seg)
    {
        return binary_search(segs.begin(), segs.end(), seg);
    };

    // check for 1 remaining -- only need to worry about going up or right since there must necessarily be a point on the other side (corresponding to down or left) if only 1 is remaining
    for(auto [p, o] : pts)
    {
        S right = {p, p}, up = right;
        right[1].first += 1;
        up[1].second += 1;
        for(auto seg : {right, up})
        {
            if(!exists(seg) && pts.count(seg[1]))
            {
                int i1 = pts[seg[0]], i2 = pts[seg[1]];
                if(dsu.find(i1) == dsu.find(i2))
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    for (auto seg : segs)
    {
        if (isHorizontal(seg))
        {
            auto t = exists(above(seg)), b = exists(below(seg));
            S tls = S{seg[0], seg[0]};
            tls[1].second++;  // keep it sorted
            S bls = below(tls);
            bool tl = exists(tls), tr = exists(right(tls));
            bool bl = exists(bls), br = exists(right(bls));

            if (t || b || tl || tr || bl || br)
            {
                cout << 2;
                return 0;
            }

            continue;
        }

        // vertical
        auto l = exists(left(seg)), r = exists(right(seg));
        S lts = S{seg[1], seg[1]};  // second point with higher y is larger
        lts[0].first--;
        S rts = right(lts);
        bool lt = exists(lts), rt = exists(rts);
        bool lb = exists(below(lts)), rb = exists(below(rts));

        if (l || r || lt || rt || lb || rb)
        {
            cout << 2;
            return 0;
        }
    }

    cout << 3;
    return 0;
}
