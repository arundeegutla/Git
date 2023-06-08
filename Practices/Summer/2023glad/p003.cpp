#include "bits/stdc++.h"

using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> inRow(n);
    vector<int> inCol(n);
    vector<vector<bool>> right(n, vector<bool> (n, false));
    vector<vector<bool>> left(n, vector<bool> (n, false));
    vector<vector<bool>> bottom(n, vector<bool> (n, false));
    vector<vector<bool>> up(n, vector<bool> (n, false));
    vector<vector<bool>> fixed(n, vector<bool> (n, false));
    vector<vector<int>> grid(n, vector<int> (n, 0));

    for(int i = 0; i < ((2*n)-1); i++) {
        int row = i/2;
        string line; cin >> line;
        if(i%2 == 0)
            for (int j = 0; j < line.length(); j++) {
                right[row][j] = line[j] == '1';
                left[row][j+1] = line[j] == '1';
            }
        else
            for (int j = 0; j < line.length(); j++) {
                bottom[row][j] = line[j] == '1';
                up[row+1][j] = line[j] == '1';
            }
    } 

    for (int i = 0; i < k; i++) {
        int r; cin >> r; r--;
        int c; cin >> c; c--;
        fixed[r][c] = true;
        cin >> grid[r][c];
        inRow[r] |= (1<<grid[r][c]);
        inCol[c] |= (1<<grid[r][c]);
    }

    auto valid = [&](int num, int row, int col, auto && valid) -> bool {
        if(num <= 0 || num > n) return false;
        if((inRow[row] & (1<<num)) != 0) return false;
        if((inCol[col] & (1<<num)) != 0) return false;
        if(fixed[row][col] && grid[row][col] != num) return false;
        
        inRow[row] |=  (1<<num);
        inCol[col] |=  (1<<num);
        grid[row][col] = num;
        
        return true;
    };

    
    auto check = [&]() -> bool {
        for(int mask : inRow)
            if((mask ^ (1<<(n+1))-1) != 1)
                return false;
        for(int mask : inCol)
            if((mask ^ (1<<(n+1))-1) != 1)
                return false;
        return true;
    };

    auto remove = [&](int num, int row, int col) -> void {
        if(fixed[row][col]) return;
        inRow[row] ^= (1<<num);
        inCol[col] ^= (1<<num);
    };

    auto cheese = [&](int num, int row, int col) -> bool {
        if(up[row][col] && fixed[row-1][col] && abs(grid[row-1][col] - num) != 1) return false;
        if(left[row][col] && fixed[row][col-1] && abs(grid[row][col-1] - num) != 1) return false;
        return true;
    };

    int minNum = n*n;
    auto go = [&] (int id, auto && go) -> bool {
        if(id==-1) return true;

        if(id < minNum) {
            minNum = id;
            cout << minNum << endl;
        }

        int row = id/n;
        int col = id%n;
        int myright = col + 1 == n ? -1 : grid[row][col+1];
        int mybottom = row + 1 == n ? -1 : grid[row+1][col];

        if(fixed[row][col]) {
            int mine = grid[row][col];
            if(bottom[row][col] && right[row][col]) {
                if(abs(mine - myright) == 1 && abs(mine - mybottom) == 1)
                    if(cheese(mine, row, col) && go(id-1, go))
                        return true;
            } else if (bottom[row][col]) {
                if(abs(mine - mybottom) == 1)
                    if(cheese(mine, row, col) && go(id-1, go))
                        return true;
            } else if (right[row][col]) {
                if(abs(mine - myright) == 1)
                    if(cheese(mine, row, col) && go(id-1, go))
                        return true;
            } else if(go(id-1, go))
                return true;
            return false;
        }

        if (bottom[row][col] && right[row][col]) {
            if (abs(myright - mybottom) == 0) {
                if(valid(myright+1, row, col, valid)) {
                    if(cheese(myright+1, row, col) && go(id-1, go))
                        return true;
                    remove(myright+1, row, col);
                }     
                if(valid(myright-1, row, col, valid)) {
                    if(cheese(myright-1, row, col) && go(id-1, go))
                        return true;
                    remove(myright-1, row, col);
                }
            } else if(abs(myright - mybottom) == 2) {
                if(valid(min(mybottom, myright)+1, row, col, valid)) {
                    if(cheese(min(mybottom, myright)+1, row, col) && go(id-1, go))
                        return true;
                    remove(min(mybottom, myright)+1, row, col);
                }
            }
            return false;

        } else if (bottom[row][col]) {
            if(valid(mybottom+1, row, col, valid)) {
                if(cheese(mybottom+1, row, col) && go(id-1, go))
                    return true;
                remove(mybottom+1, row, col);
            }
            if(valid(mybottom-1, row, col, valid)) {
                if(cheese(mybottom-1, row, col) && go(id-1, go))
                    return true;
                remove(mybottom-1, row, col);
            }
            return false;
        } else if (right[row][col]) {
            if(valid(myright+1, row, col, valid)) {
                if(cheese(myright + 1, row, col) && go(id-1, go))
                    return true;
                remove(myright+1, row, col);
            }     
            if(valid(myright-1, row, col, valid)) {
                if(cheese(myright-1, row, col) && go(id-1, go))
                    return true;
                remove(myright-1, row, col);
            }
            return false;
        }

        for (int i = 1; i <= n; i++) {
            if(cheese(i, row, col) && abs(mybottom-i) > 1 && abs(myright-i) > 1 && valid(i, row, col, valid)) {
                if(go(id-1, go))
                    return true;
                remove(i, row, col);
            }
        }

        return false;
    };

    go(n*n - 1, go);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cout << grid[i][j] << (j==n-1?" \n" : " ");    
}