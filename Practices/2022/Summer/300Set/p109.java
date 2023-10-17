import java.util.*;
/**
 * movingpoints
 */
public class p109 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int numBalls = in.nextInt();
            int speed = in.nextInt();
            if (numBalls==0&&speed==0)break;
            Ball[] balls = new Ball[numBalls];
            for (int i = 0; i < numBalls; i++)
                balls[i] = new Ball(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());

            System.out.printf("%.2f\n", tspHelper(balls, speed));
        }
    }

    public static double tspHelper(Ball[] balls, double speed) {
        int n = balls.length;
        Catcher[][] memo = new Catcher[1<<n][n];
        Catcher shortest = new Catcher(0, 0, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++){
            Catcher catcherLast = tsp(1<< i, i, balls, memo, speed);
            if (catcherLast.t < shortest.t) shortest = catcherLast;
        }
        return shortest.t;
    }
    
    public static Catcher tsp(int visited, int current, Ball[] balls, Catcher[][] memo, double speed) {
        if (memo[visited][current] != null)
            return memo[visited][current];
    
        // go from (0, 0) --> current catcher
        if (visited == ((1<<balls.length) - 1))
            return getCatcher(new Catcher(0, 0, 0), balls[current], speed);
    
        Catcher shortest = new Catcher(0, 0, Integer.MAX_VALUE);
        for (int i = 0; i < balls.length; i++)
            if ((visited & (1<<i)) == 0){
                // get shortest time here
                Catcher catcherLast = tsp(visited | (1<<i), i, balls, memo, speed);
                // get where catcher end up going after current at shortest time.
                Catcher c = getCatcher(catcherLast, balls[current], speed);
                if (c.t < shortest.t) shortest = c;
            }
        
        return memo[visited][current] = shortest;
    }

    private static Catcher getCatcher(Catcher catcher, Ball ball, double speed) {
        
        double a = ((ball.vx*ball.vx)+(ball.vy*ball.vy))-(speed*speed);

        double betax = -(ball.x+(ball.vx*catcher.t)) + catcher.x;
        double bx = 2*(-ball.vx*betax);
        double cx = betax*betax;

        double betay = -(ball.y+(ball.vy*catcher.t)) + catcher.y;
        double by = 2*(-ball.vy*betay);
        double cy = betay*betay;

        double b = bx+by;
        double c = cx+cy;

        double pos = (-b + Math.sqrt((b*b) - (4*a*c))) / (2*a);
        double neg = (-b - Math.sqrt((b*b) - (4*a*c))) / (2*a);

        double time = catcher.t;
        if (pos > 0 && neg > 0) time += Math.min(pos, neg);
        else time += Math.max(pos, neg);

        double x = ball.vx*time + ball.x;
        double y = ball.vy*time + ball.y;

        return new Catcher(x, y, time);
    }
}

class Ball {
    double x, y, vx, vy;
    Ball(double x, double y, double degrees, double speed) {
        this.x = x;
        this.y = y;
        vx = speed * Math.cos(Math.toRadians(degrees));
        vy = speed * Math.sin(Math.toRadians(degrees));
    }
}

class Catcher {
    double x, y, t;
    Catcher(double x, double y, double t) {
        this.x = x;
        this.y = y;
        this.t = t;
    }
}
