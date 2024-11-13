#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query {
    int x, y;
    string name;
};      

int main(){
    vector<Query> arr;
    arr.push_back({1, 0, "arun"});
    arr.push_back({0, 1, "a"});
    sort(begin(arr), end(arr));

    for(auto x : arr) {
        cout << "{" << x.x << " " << x.y << " " << x.name << "}\n";
    }
}