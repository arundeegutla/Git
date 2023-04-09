import java.util.*;

public class swan_perms {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();


        for (int i = 0; i < numCases; i++) {

            int importantLocations = in.nextInt() + 1;
            Location[] allLocations = new Location[importantLocations];

            allLocations[0] = new Location(1000, in.nextInt());
            
            int speed = in.nextInt();

            for (int j = 1; j < importantLocations; j++) { 
                allLocations[j] = new Location(in.nextInt(), in.nextInt());
            }


            int[] perm = new int[importantLocations];
            boolean[] used = new boolean[importantLocations];

            perm[0] = 0;
            used[0] = true;
            
            System.out.format("%.2f\n", getShortestDistance(allLocations, perm, used, 1)/speed);

        }

        in.close();
    }

    public static double getShortestDistance(Location[] allLocations, int[] perm, boolean[] used, int index) {
        
        if (index == allLocations.length) {
            return getDistance(allLocations[perm[index-1]], allLocations[0]);
        }


        double shortestPath = Double.MAX_VALUE;

        for (int i = 0; i < allLocations.length; i++) {
            if (!used[i]) {

                used[i] = true;
                perm[index] = i;
                double distance = getDistance(allLocations[i], allLocations[perm[index-1]]) + getShortestDistance(allLocations, perm, used, index+1);

                if(distance < shortestPath) shortestPath = distance;

                used[i] = false;
            }
        }


        return shortestPath;
    }


    public static double getDistance(Location a, Location b) {

        int a2 = a.distFromOrigin * a.distFromOrigin;
        int b2 = b.distFromOrigin * b.distFromOrigin;
        int ab2 = (2*a.distFromOrigin*b.distFromOrigin);

        return Math.sqrt((a2 + b2) - (ab2 * Math.cos(Math.toRadians(Math.abs(a.angle - b.angle)))));
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
