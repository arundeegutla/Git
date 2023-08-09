#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

void solve(){
    string v = "aeiou";
    vector<string> last;
    vector<int> syllycount;
    string s;
    int sylly = 0;
    
    bool newVers = false;
    bool end = false;
    while(!end){
        cin >> s;
        if(s[s.size()-1]==',' || s[s.size()-1]=='.'){
            s = s.substr(0, s.size() - 1);
            newVers = true;
        }

        if(s[s.size()-1]=='.')
            end = true;

        if(s.length() == 6) {
            if(s.find("ng") != s.npos || s.find("ny") != s.npos){
                sylly += 2;
                if(newVers){
                    syllycount.push_back(sylly);
                    last.push_back(s);
                    sylly = 0;
                }
                continue;
            }
        }
        if(s.length() == 3) {
            if(v.find(s[0]) != v.npos){
                sylly += 2;
                if(newVers){
                    syllycount.push_back(sylly);
                    last.push_back(s);
                    sylly = 0;
                }
                continue;
            }
        }

        if(s.length() >= 6){
            sylly += 3;
        } else if (s.length() >= 4) {
            sylly += 2;
        } else {
            sylly += 1;
        }
        if(newVers){
            syllycount.push_back(sylly);
            last.push_back(s);
            sylly = 0;
        }
    }

    // for(auto l : syllycount){
    //     cout << l << " ";
    // }
    cout << "\n";
    int n = last.size();
    vector<int> points(5);
    for(int i = 0; i < min(n, 4); i++)
        points[0] += syllycount[i] >= 8 && syllycount[i] <= 12 ? 10 : 0;

    for(int i = 0; i+2 < min(n, 4); i++)
        if(last[i][last[i].size()-2] == last[i+2][last[i+2].size()-2] && last[i][last[i].size()-1] == last[i+2][last[i+2].size()-1])
            points[1] += 20;

    for(int i = 0; i+2 < min(n, 4); i++)
        if(syllycount[i] == syllycount[i+2])
            points[2] += 10;

    points[3] = n>4?(n-4)*10:0;

    for(int i = 0; i < 3; i++)
        points[4] += points[i];
    points[4] -= points[3];

    for(int i = 0; i < 5; i++)
        cout << points[i] << (i==4?"\n":" ");

}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}