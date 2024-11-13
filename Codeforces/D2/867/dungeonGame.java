import java.awt.*;
class Solution {
    public int[][] D = {{0, 1}, {1, 0}};

    public int calculateMinimumHP(int[][] dungeon) {

        int n = dungeon.length;
        int m = dungeon[0].length;

        Boolean[][][] memo = new Boolean[n][m][2001];

        int lo = 1;
        int high = 2000;

        while(lo < high) {
            int mid = (high+lo)/2;
            if(go(0, 0, mid, memo, dungeon)) 
                high = mid;
            else 
                lo = mid+1;
        }
        
        return high;
    }

    public boolean go(int x, int y, int health, Boolean[][][] memo, int[][] dungeon) {
        int n = memo.length;
        int m = memo[0].length;
        if(x<0||x>=n||y<0||y>=m||health<=0) return false;

        if(x==n-1&&y==m-1) 
            return health + dungeon[x][y] > 0;

        if(memo[x][y][health] != null) 
            return memo[x][y][health];

        if(go(x, y+1, health+dungeon[x][y], memo, dungeon)) 
            return memo[x][y][health] = true;

        return memo[x][y][health] = go(x+1, y, health+dungeon[x][y], memo, dungeon);
    }
}