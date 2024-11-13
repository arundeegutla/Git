/*  This problem reduces to the CSES problem Path Queries II

    Solution Idea:
    1. Given the graph G from the problem's input, compute the MST of G and the sum of all edges in that MST.
    2. Use binary lifting to calculate the max value on paths to ancestors.
    3. For each query with edge E with nodes a and b, and weight c
        a. If E exists in the MST already, then the MST we would create after repairing that road
            would be the same as our precomputed one (answer is just mstTotal).
        b. If E does NOT exist in the MST already, then if we were to add that edge to our precomputed MST,
            it would create a binconnected component containing E, and every edge in the MST on the path from a to b. 
            Since it is a biconnected component, we can remove any edge from that bicomp and the resultant graph will 
            still be a tree (in fact, it will be the MST which includes E). Since we can remove any one edge from the bicomp
            and the graph will still be a tree, we should remove the edge with highest weight on the path from a to b.
            Our answer will be: mstTotal + c - maxEdgeWeightOnPathAtoB.
*/


#include <bits/stdc++.h>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 1<<17;
const int LOGN = 17;
int n, r, q;

struct Edge {
    int a, b, c;

    Edge(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
    }

    Edge() {
        a = b = c = 0;
    }

    bool operator<(Edge const& o) {
        return c < o.c;
    }
};

struct DSU {
    int n;
    vector<int> p;
    vector<int> size;

    DSU(int nn) {
        n = nn;
        p = vector<int>(n+1);
        size = vector<int>(n+1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int v) {
        if (p[v] != v)
            p[v] = find(p[v]);
        return p[v];
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;
        
        if (size[a] < size[b])
            swap(a, b);
        
        p[b] = a;
        size[a] += size[b];
        return true;
    }
};

int mstTotal;
vector<Edge> eList;
vector<vector<pair<int, int>>> mst;
vector<vector<pair<int, int>>> anc;
vector<int> level;

void dfs(int cur, int pre, int l) {
    level[cur] = l;

    for (auto nxt : mst[cur]) {
        if (nxt.first != pre) {
            anc[0][nxt.first] = {cur, nxt.second};
            dfs(nxt.first, cur, l+1);
        }
    }
}

void kruskal() {
    // Calculates MST for input graph
    DSU dsu(n); 
    mst = vector<vector<pair<int, int>>>(n+1);
    mstTotal = 0;
    sort(eList.begin(), eList.end());
    int numComps = n;

    for (Edge e : eList) {
        if (dsu.join(e.a, e.b)) {
            mstTotal += e.c;
            mst[e.a].push_back({e.b, e.c});
            mst[e.b].push_back({e.a, e.c});
            numComps--;
        }

        if (numComps == 1)
            break;
    }

    anc = vector<vector<pair<int, int>>>(LOGN, vector<pair<int, int>>(n+1)); // BL table
    level = vector<int>(n+1, 0); // Stores depth of each node
    anc[0][1] = {0, 0};
    dfs(1, 0, 1); // Calcs depth and parent of each node

    // Binary lifting
    for (int exp = 1; exp < LOGN; exp++) {
        for (int i = 1; i <= n; i++) {
            anc[exp][i].first = anc[exp-1][anc[exp-1][i].first].first;
            anc[exp][i].second = max(anc[exp-1][i].second, anc[exp-1][anc[exp-1][i].first].second);
        }
    }
}

int query(int a, int b, int c) {
    // LCA
    if (level[b] > level[a])
        swap(a, b);

    int maxEdge = 0;
    int diff = level[a] - level[b];

    for (int i = LOGN - 1; i >= 0; i--) {
        if (level[a] - (1<<i) >= level[b]) {
            maxEdge = max(maxEdge, anc[i][a].second);
            a = anc[i][a].first;
        }
    }

    if (a == b) {
        if (diff == 1) // Case 3a from solution idea
            return mstTotal;
        else
            return (mstTotal + c - maxEdge);
    }

    for (int i = LOGN-1; i >= 0; i--) {
        if (anc[i][a].first != anc[i][b].first) {
            maxEdge = max(maxEdge, anc[i][a].second);
            maxEdge = max(maxEdge, anc[i][b].second);
            a = anc[i][a].first;
            b = anc[i][b].first;
        }
    }

    maxEdge = max(maxEdge, anc[0][a].second);
    maxEdge = max(maxEdge, anc[0][b].second);

    return (mstTotal + c - maxEdge);
}

int main() {
    cin >> n >> r;

    vector<map<int, int>> cost(n+1);

    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cost[a][b] = c;
        cost[b][a] = c;
        eList.push_back(Edge(a, b, c));
    }

    kruskal();

    cin >> q;

    while (q--) {
        int a, b; cin >> a >> b;
        int c = cost[a][b];
        cout << query(a, b, c) << endl;
    }
}