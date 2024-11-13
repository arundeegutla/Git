import java.util.Arrays;
import java.util.Scanner;

public class h {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int LOWEST = (int)1e9;

        int maxHots = 0;
        int numHots = in.nextInt();
        int[] hotdogs = new int[numHots];
        for (int i = 0; i < hotdogs.length; i++){
            hotdogs[i] = in.nextInt();
            maxHots += hotdogs[i];
        }

        int maxBuns = 0;
        int numBuns = in.nextInt();
        int[] buns = new int[numBuns];
        for (int i = 0; i < buns.length; i++){
            buns[i] = in.nextInt();
            maxBuns += buns[i];
        }

        int max = Math.min(maxBuns, maxHots);
        
        int[][] hotsmemo = new int[hotdogs.length][max + 1];
        for (int[] js : hotsmemo)
            Arrays.fill(js, -1);

        int[][] bunsmemo = new int[buns.length][max + 1];
        for (int[] js : bunsmemo) 
            Arrays.fill(js, -1);


        for (int i = 1; i <= max; i++) {
            int xhots = getMin(0, i, hotdogs, hotsmemo);            
            int xbuns = getMin(0, i, buns, bunsmemo);            
            LOWEST = Math.min(LOWEST, xbuns + xhots);
        }

        if (LOWEST >= (int)1e9) {
            System.out.println("impossible");
            return;
        }


        System.out.println(LOWEST);


    }

    private static int getMin(int at, int need, int[] arr, int[][] memo) {

        if (need == 0)
            return 0;

        if (need < 0 || at == arr.length)
            return (int)1e9;

        if(memo[at][need] != -1)
            return memo[at][need];

        int ans = Math.min(getMin(at+1, need, arr, memo), 1 + getMin(at+1, need-arr[at], arr, memo));
        memo[at][need] = ans;

        return ans;
    }

}
