import java.lang.reflect.Array;
import java.util.*;

public class swan {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();


        for (int i = 0; i < numCases; i++) {

            int importantLocations = in.nextInt() + 1;
            Location[] allLocations = new Location[importantLocations];

            allLocations[0] = new Location(1000, in.nextInt());
            
            int speed = in.nextInt();

            for (int j = 1; j < importantLocations; j++)
                allLocations[j] = new Location(in.nextInt(), in.nextInt());

            
            System.out.format("%.2f\n", getShortestDistance(allLocations)/speed);

        }

        in.close();
    }

    private static double getShortestDistance(Location[] allLocations) {
        int n = allLocations.length;
        double[][] memo = new double[1<<n][n];
        for (double[] oneD : memo)
            Arrays.fill(oneD, -1);

        double shortest = 1e9;
        for (int i = 0; i < n; i++)
            shortest = Math.min(shortest, tsp((1<<n) - 1, i, allLocations, memo) + getDistance(allLocations[i], allLocations[0]));

        return shortest;
    }

    private static double tsp(int mask, int next, Location[] allLocations, double[][] memo) {
        if (memo[mask][next] != -1)
            return memo[mask][next];

        if (Integer.bitCount(mask) == 1) {
            return getDistance(allLocations[0], allLocations[next]);
        }

        int oldmask = mask - (1<<next);

        double min = 1e9;
        for (int i = 0; i < allLocations.length; i++)
            if ((oldmask & (1<<i)) != 0)
                min = Math.min(min, tsp(oldmask, i, allLocations, memo) + getDistance(allLocations[i], allLocations[next]));
        
        return memo[mask][next] = min;
    }


    public static double getDistance(Location a, Location b) {
        int a2 = a.distFromOrigin * a.distFromOrigin;
        int b2 = b.distFromOrigin * b.distFromOrigin;
        int ab2 = (2*a.distFromOrigin*b.distFromOrigin);
        return Math.sqrt((a2 + b2) - (ab2 * Math.cos(Math.toRadians(Math.abs(a.angle - b.angle)))));
    }


    private static double tspHelper(Location[] allLocations) {

        int n = allLocations.length;

        int[][] memo = new int[1<<n][n];
        for (int[] oneD : memo)
            Arrays.fill(oneD, -1);
            
        int shortest = (int)1e9;
        // Test all endings.
        for (int i = 0; i < n; i++)
        {
            //                     include all bits --> end i           i --> start
            int thisShortest = tsp((1<<n) - 1, i, allLocations, memo) + getDistance(allLocations[i], allLocations[0]);
            shortest = Math.min(shortest, thisShortest);
        }

        return shortest;
    }

    private static int tsp(int mask, int next, Location[] allLocations, int[][] memo) {
        if (memo[mask][next] != -1)
            return memo[mask][next];

        if (Integer.bitCount(mask) == 1)
            // start --> first location.
            return getDistance(allLocations[0], allLocations[next]);


        // remove next location from mask.
        int oldmask = mask - (1<<next);

        int min = (int)1e9;
        for (int i = 0; i < allLocations.length; i++)
            if ((oldmask & (1<<i)) != 0) // if oldmask has the next index.
                min = Math.min(min, tsp(oldmask, i, allLocations, memo) + getDistance(allLocations[i], allLocations[next]));
        
        return memo[mask][next] = min;
    }




}

class Location{
    public int distFromOrigin;
    public int angle;

    public Location(int distFromOrigin, int angle){
        this.distFromOrigin = distFromOrigin;
        this.angle = angle;
    }
}
