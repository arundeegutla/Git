#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool inBounds(ll x, ll nodeCount)
{
    if (x >= 0 && x < nodeCount)
        return true;
    return false;
}


int main()
{
    int r,c; cin >> r >> c;
    int nodeCount = r*c;
    vector<pair<ll,ll>> nodes(nodeCount);

    for (int i = 0; i < nodeCount; i++)
    {
        // cout << "here " << endl;
        cin >> nodes[i].second;
        nodes[i].first = INT_MAX;
    }
    priority_queue<pair<pair<ll,ll>, ll>, vector<pair<pair<ll,ll>,ll>>, greater<pair<pair<ll,ll>,ll>>> minQ;
    for (int i = 0; i < nodeCount; i+=c)
    {
        // cout << "there " << endl;

        nodes[i].first = nodes[i].second;
        minQ.push(make_pair(nodes[i],i));
    }

    while (!minQ.empty())
    {
        // cout << "IN" << endl;
        pair<ll,ll> currVals = minQ.top().first;
        int currNode = minQ.top().second;
        minQ.pop();

        vector<ll> change = {currNode-1, currNode+1, currNode+c,currNode-c};

        if (currNode % c == 0)
            change[0] = -1;
        else if (currNode % c == c-1)
            change[1] = -1;

        for (auto x: change)
        {
            if (inBounds(x,nodeCount))
            {
                pair<ll,ll> newVals = nodes[x];
                if (currVals.first < newVals.first)
                {
                    newVals.first = currVals.first;
                    if (newVals.first < newVals.second)
                        newVals.first = newVals.second;
                    minQ.push(make_pair(newVals, x));
                }
                nodes[currNode] = currVals;
                nodes[x] = newVals;

            }
        }
    }
    ll minVal = LLONG_MAX;
    for (int i = c-1; i < nodeCount; i+=c)
    {
       minVal = min(minVal, nodes[i].first); 
    }

    cout << minVal << endl;

}
