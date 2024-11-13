#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    unordered_map<string, int> id;
    unordered_map<int, string> name;

    vector<vector<int>> graph;
    getline(cin, *(new string()));
    while(n--){
        string s; getline(cin, s);
        stringstream sin(s);

        vector<string> split;
        while(sin.good()) {
            string p; sin >> p;
            split.push_back(p);
        }

        for(auto x : split){
            if(id.find(x) == id.end()){
                name[id.size()] = x;
                id[x] = id.size();
                graph.push_back(*(new vector<int>));
            }
        }

        int from = id[split[0]];
        for(int i = 1; i < split.size(); i++){
            graph[from].push_back(id[split[i]]);
            graph[id[split[i]]].push_back(from);
        }
    }

    string s, e; cin >> s >> e;
    if(id.find(s) == id.end() || id.find(e) == id.end()){
        cout << "no route found\n";
        return 0;
    }

    int from = id[s], to = id[e];

    vector<int> seen(id.size());
    vector<int> path;
    auto dfs = [&](int at, auto && dfs) -> bool {
        path.push_back(at);
        seen[at] = true;
        if(at == to) return true;
        for(auto e : graph[at])
            if(!seen[e] && dfs(e, dfs))
                return true;
        path.pop_back();
        seen[at] = false;
        return false;
    };

    if(dfs(from, dfs))
        for(int i = 0; i < path.size(); i++)
            cout << name[path[i]] << (i==path.size()-1 ? "\n" : " ");
    else
        cout << "no route found\n";
}