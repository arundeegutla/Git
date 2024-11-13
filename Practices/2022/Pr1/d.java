
import java.util.Scanner;

public class d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCoors = in.nextInt();

        int[][] coordinates = new int[numCoors][2];

        for (int i = 0; i < numCoors; i++) {

            

            int x = in.nextInt();
            int y = in.nextInt();

            coordinates[i][0] = x;
            coordinates[i][1] = y;

            
        }
        

        System.out.println(getNumberTotal(coordinates));


    }

    private static int getNumberTotal(int[][] coordinates) {
        int[] total = new int[coordinates.length];
        return getCombos(total, 0, coordinates.length, coordinates);
    }

    public static int getCombos(int[] subset, int k, int n, int[][] coordinates) {


        if (k == n){
            return ifcanorigin(subset, coordinates);
        }
    
        int total = 0;

        total += getCombos(subset, k+1, n, coordinates);

        subset[k] = 1;
        total += getCombos(subset, k+1, n, coordinates);
        subset[k] = 0;

        return total;
    
    }

    

    private static int ifcanorigin(int[] subset, int[][] coordinates) {

        int x = 0;
        int y = 0;
        boolean changed = false;


        for (int i = 0; i < subset.length; i++) {
            if (subset[i] == 1) {
                changed = true;
                x += coordinates[i][0];
                y += coordinates[i][1];
            }
        }
        
        return x == 0 && y == 0 && changed ? 1 : 0;
    }

}
