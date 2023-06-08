import java.util.Scanner;

public class p003 {
    static int n;
    static int[] inRow;
    static int[] inCol;
    static boolean[][] right;
    static boolean[][] bottom;
    static int[][] grid;
    static boolean[][] fixed;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int k= in.nextInt();
        
        inRow = new int[n];
        inCol = new int[n];
        right = new boolean[n][n];
        bottom = new boolean[n][n];
        fixed = new boolean[n][n];
        grid = new int[n][n];
        

        for(int i = 0; i < ((2*n)- 1); i++) {
            int row = i/2;
            String line = in.next();
            if(i%2 == 0)
                for (int j = 0; j < line.length(); j++)
                    right[row][j] = line.charAt(j) == '1';
            else
                for (int j = 0; j < line.length(); j++)
                    bottom[row][j] = line.charAt(j) == '1';
        }   

        for (int i = 0; i < k; i++) {
            int r = in.nextInt() - 1;
            int c = in.nextInt() - 1;
            fixed[r][c] = true;
            grid[r][c] = in.nextInt();
            inRow[r] |= (1<<grid[r][c]);
            inCol[c] |= (1<<grid[r][c]);
        }
        
        go(n*n-1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                System.out.print((grid[i][j]) + (j==n-1?" \n":" "));
    }

    private static boolean go(int id) {
        if(id==-1) return check();

        int row = id/n;
        int col = id%n;
        int myright = col + 1 == n ? -1 : grid[row][col+1];
        int mybottom = row + 1 == n ? -1 : grid[row+1][col];

        if(fixed[row][col]) {
            int mine = grid[row][col];
            if(bottom[row][col] && right[row][col]) {
                if(Math.abs(mine - myright) == 1 && Math.abs(mine - mybottom) == 1)
                    if(go(id-1))
                        return true;
            } else if (bottom[row][col]) {
                if(Math.abs(mine - mybottom) == 1)
                    if(go(id-1))
                        return true;
            } else if (right[row][col]) {
                if(Math.abs(mine - myright) == 1)
                    if(go(id-1))
                        return true;
            } else if(go(id-1))
                return true;
            return false;
        }

        if (bottom[row][col] && right[row][col]) {
            if (Math.abs(myright - mybottom) == 0) {
                if(valid(myright+1, row, col)) {
                    if(go(id-1))
                        return true;
                    remove(myright+1, row, col);
                }     
                if(valid(myright-1, row, col)) {
                    if(go(id-1))
                        return true;
                    remove(myright-1, row, col);
                }
            } else if(Math.abs(myright - mybottom) == 2) {
                if(valid(Math.min(mybottom, myright)+1, row, col)) {
                    if(go(id-1))
                        return true;
                    remove(Math.min(mybottom, myright)+1, row, col);
                }
            }
            return false;

        } else if (bottom[row][col]) {
            if(valid(mybottom+1, row, col)) {
                if(go(id-1))
                    return true;
                remove(mybottom+1, row, col);
            }
            if(valid(mybottom-1, row, col)) {
                if(go(id-1))
                    return true;
                remove(mybottom-1, row, col);
            }
            return false;
        } else if (right[row][col]) {
            if(valid(myright+1, row, col)) {
                if(go(id-1))
                    return true;
                remove(myright+1, row, col);
            }     
            if(valid(myright-1, row, col)) {
                if(go(id-1))
                    return true;
                remove(myright-1, row, col);
            }
            return false;
        }
    

        for (int i = 1; i <= n; i++) {
            if(Math.abs(mybottom-i) > 1 && Math.abs(myright-i) > 1 && valid(i, row, col)) {
                if(go(id-1))
                    return true;
                remove(i, row, col);
            }
        }

        return false;
    }

    private static boolean check() {
        for(int mask : inRow)
            if((mask ^ (1<<n+1)-1) != 1)
                return false;
        for(int mask : inCol)
            if((mask ^ (1<<n+1)-1) != 1)
                return false;
        return true;
    }

    private static void remove(int num, int row, int col) {
        if(fixed[row][col]) return;
        inRow[row] ^= (1<<num);
        inCol[col] ^= (1<<num);
    }

    private static boolean valid(int num, int row, int col) {
        if(num <= 0 || num > n) return false;
        if((inRow[row] & (1<<num)) != 0) return false;
        if((inCol[col] & (1<<num)) != 0) return false;
        if(fixed[row][col] && grid[row][col] != num) return false;
        
        inRow[row] |=  (1<<num);
        inCol[col] |=  (1<<num);
        grid[row][col] = num;
        
        return true;
    }
}
