import java.util.*;

public class narrowArtSlow {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numRows = in.nextInt();
        int numToOff = in.nextInt();


        while (numRows != 0) {

            int total = 0;
            int[][] rooms = new int[numRows][2];

            for (int i = 0; i < numRows; i++) {
                rooms[i][0] = in.nextInt();
                rooms[i][1] = in.nextInt();

                total += rooms[i][0];
                total += rooms[i][1];
            }

            int minRemoval = getMinRemoval(rooms, numToOff);


            System.out.println(total - minRemoval);

            numRows = in.nextInt();
            numToOff = in.nextInt();
        }

        in.close();


    }

    private static int getMinRemoval(int[][] rooms, int numRemoval) {

        int[][][] dp = new int[rooms.length+1][numRemoval+1][3];

        for (int i = numRemoval; i > 0; i--) {
            for (int j = 0; j < 3; j++) {
                dp[rooms.length][i][j] = (int)1e9;
            }
        }

        for (int level = rooms.length - 1; level >= 0; level--) 
        {
            for (int removes = 1; removes <= numRemoval; removes++) {
                
                for (int prevState = 0; prevState < 3; prevState++) {

                    int didnt = dp[level+1][removes][0];

                    if (prevState == 1 || prevState == 2) {
                        int did = rooms[level][prevState - 1] + dp[level+1][removes - 1][prevState];
                        dp[level][removes][prevState] = Math.min(didnt, did);
                    } else {

                        int tookLeft = rooms[level][0] + dp[level+1][removes-1][1];
                        int tookRight = rooms[level][1] + dp[level+1][removes-1][2];

                        dp[level][removes][prevState] = Math.min(didnt, Math.min(tookLeft, tookRight));

                    }
                }
            }
        }

        return Math.min(dp[0][numRemoval][0], Math.min(dp[0][numRemoval][1], dp[0][numRemoval][2]));
    
    }

}
