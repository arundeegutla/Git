import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.geom.*;

public class movingpoints {
    public static MPoint[] ALLPOINTS;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt(), c = in.nextInt();
            if (n == 0 && c == 0)
                return;
            
            ALLPOINTS = new MPoint[n];
            for (int i = 0; i < args.length; i++) {
                ALLPOINTS[i] = new MPoint(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
            }

            System.out.println(tspHelper(c));
            
        }
    }

    public static double tspHelper(int catchSpeed) {
        int n = ALLPOINTS.length;
        double[][] memo = new double[1<<n][n];
        for (double[] oneD : memo) Arrays.fill(oneD, -1);
        double shortestTime = 1e9;
        for (int i = 0; i < n; i++){
            double thisShortest = tsp(1<< i, i, memo, catchSpeed);
            shortestTime = Math.min(shortestTime, thisShortest);
        }
        return shortestTime;
    }
    
    public static double tsp(int visited, int current, double[][] memo, int catchSpeed) {
        if (memo[visited][current] != -1)
            return memo[visited][current];
    
        if (visited == ((1<<ALLPOINTS.length) - 1))
            return ;
    
        double min = 1e9;
        for (int i = 0; i < ALLPOINTS.length; i++)
            if ((visited & (1<<i)) == 0)
                min = Math.min(min, tsp(visited | (1<<i), i, memo) + dist[current][i]);
        
        return memo[visited][current] = min;
    }

}

class Catcher {

    

}


class MPoint {
    Point start;
    double xSlope;
    double ySlope;
    double yspeed;
    double xspeed;
    int angle;
    MPoint(int x, int y, int angle, int speed) {
        start = new Point(x, y);
        this.angle = angle;
        xSlope = Math.cos(Math.toRadians(angle));
        ySlope = Math.sin(Math.toRadians(angle));
        yspeed = speed * Math.sin(Math.toRadians(angle));
        xspeed = speed * Math.cos(Math.toRadians(angle));
    }
}
