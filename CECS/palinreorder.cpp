#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    unordered_map<char, int> hmap;
    for(auto c : s) hmap[c]++;
    char mid = '-';
    int count = 0;
    string half;
    for(auto [c, v] : hmap){
        if(v%2) {
            if(mid!='-'){
                cout << "NO SOLUTION\n";
                return 0;
            }
            mid = c;
            count = v;
        } else {
            for(int i = 0; i < v/2; i++)
                half.push_back(c);
        }
    }

    string rev(half);
    reverse(rev.begin(), rev.end());
    if(mid!='-')
        for(int i = 0; i < count; i++)
            half.push_back(mid);
    half += rev;
    cout << half;

}