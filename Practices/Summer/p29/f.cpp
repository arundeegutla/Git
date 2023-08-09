#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree{
    int n;
    vector<ll> sum, lazy;
    SegTree(int n) {
		this->n = n;
        int len = n * 4 + 1;
        sum = vector<ll>(len);
        lazy = vector<ll>(len);
    }
    void push(int i){
        sum[2*i] += lazy[i];
        lazy[2*i] += lazy[i];
        sum[2*i+1] += lazy[i];
        lazy[2*i+1] += lazy[i];
        lazy[i] = 0;
    }
	
    void add(int s, int e, ll val, int li=0, int ri=-1, int i=1){
        if(ri == -1) ri = n - 1;
        if(s <= li && ri <= e) {
            minn[i] += val;
            lazy[i] += val;
            return;
        }
        push(i);
        int mi = (li + ri) / 2;
        if(s <= mi) add(s, e, val, li, mi, 2*i);
        if(e > mi) add(s, e, val, mi + 1, ri, 2*i+1);

        minn[i] = min(minn[2*i], minn[2*i+1]);
    }

    ll getMin(int s, int e, int li=0, int ri=-1, int i=1){
        if(ri == -1) ri = n - 1;

        if(s <= li && ri <= e) return minn[i];

        push(i);

        ll out = 1e18;
        int mi = (li + ri) / 2;
        if(s <= mi) out = min(out, getMin(s, e, li, mi, 2*i));
        if(e > mi) out = min(out, getMin(s, e, mi + 1, ri, 2*i+1));

        return out;
    }
};