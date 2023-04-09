import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class prob10 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int num = 1;
        while (true) {
            int rods = s.nextInt(), drops = s.nextInt();

            if (drops == 0) break;

            ArrayList<Rod> rodList = new ArrayList<Rod>();
            for (int i = 0; i < rods; i++) {
                int x = s.nextInt(), y = s.nextInt(), r = s.nextInt();
                rodList.add(new Rod(x, y, r));
            }
            Collections.sort(rodList);

            System.out.println("Test set " + num);

            // Simulate each drop from different x values
            for (int i = 0; i < drops; i++) {
                int startingX = s.nextInt();
                double totalDist = 0, currHeight = 1200;

                for (Rod currRod : rodList) {
                    if (startingX < currRod.x + currRod.r && startingX > currRod.x && currHeight >= currRod.y) { // hit on right
                        double angle = Math.acos((startingX - currRod.x) / (double) currRod.r);

                        totalDist += currHeight - currRod.y - (Math.sin(angle) * currRod.r); // Dist from previous point to circle
                        totalDist += angle * currRod.r; // Dist around circle

                        startingX = currRod.x + currRod.r;
                        currHeight = currRod.y;
                    } else if (startingX > currRod.x - currRod.r && startingX <= currRod.x && currHeight >= currRod.y) { // hit on left or middle
                        double angle = Math.acos((currRod.x - startingX) / (double) currRod.r);

                        totalDist += currHeight - currRod.y - (Math.sin(angle) * currRod.r); // Dist from previous point to circle
                        totalDist += angle * currRod.r;
                        
                        startingX = currRod.x - currRod.r;
                        currHeight = currRod.y;
                    }
                }

                totalDist += currHeight;

                System.out.printf("%.4f\n", totalDist);
                num++;
            }
            System.out.println();
        }
    }
}

class Rod implements Comparable<Rod> {

    int x, y, r;

    Rod(int x, int y, int r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    @Override
    public int compareTo(Rod o) {
        return (o.y + o.r) - (this.y + this.r);
    }
}