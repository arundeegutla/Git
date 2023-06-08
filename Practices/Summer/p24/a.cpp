#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}
int D[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}, {-1, -1},{1, 1}};

double det(vector<vector<double>>& a) {
    int n = a.size();
    double res = 1;
    for (int i = 0; i < n; i++) {
        int b = i;
        for (int j = i+1; j < n; j++)
            if(fabs(a[j][i] > fabs(a[b][i])))
                b = j;
        if(i!=b) swap(a[i], a[b]), res *= -1;
        res *= a[i][i];
        if(res == 0) return 0;
        for (int j = i+1; j < n; j++){
            double v = a[j][i] / a[i][i];
            if(v!=0) for (int k = i+1; k < n; k++)
                a[j][k] -= v * a[i][k];
        }
    }
    return res;
}

void solve(){
    int x = nextInt();
    vector<vector<int>> grid(x*x, vector<int>(x*x));
    vector<int> count(x*x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            for (auto d : D) {
                int nRow = i+d[0];
                int nCol = j+d[1];
                if(nRow<0||nRow>=(x)||nCol<0||nCol>=(x)) continue;
                int from = (i*(x))+j;
                int to = (nRow*(x))+nCol;
                grid[from][to] = 1;
                count[from]++;
            }
        }
    }


    vector<vector<int>> matrix(x*x, vector<int>(x*x));
    for (int i = 0; i < x*x; i++) {
        for (int j = 0; j < x*x; j++) {
            if(i!=j){
                matrix[i][j] = grid[i][j] == 1? -1:0;
                continue;
            }
            matrix[i][j] = count[i];
        }
    }

    vector<vector<double>> newMatrix(x*x - 1, vector<double>(x*x - 1));
    for (int i = 0; i < newMatrix.size(); i++)
        for (int j = 0; j < newMatrix.size(); j++) 
            newMatrix[i][j] = matrix[i+1][j+1];

    double ans = det(newMatrix);
    ans = round(ans*1000)/1000;
    cout << (ll)ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}