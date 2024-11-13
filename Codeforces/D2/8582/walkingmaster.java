import java.util.Scanner;

/**
 * walkingmaster
 */
public class walkingmaster {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            long a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
            
            int numMoves = 0;
            while (a!=c || b!=d) {
                if (b>d)
                    break;
                if (c-a != d-b) {
                    long dist2 = d-b;
                    long shouldStart = c - dist2;
                    if (shouldStart > a)
                        break;
                    numMoves += a-shouldStart;
                    a = shouldStart;
                } else {
                    numMoves += c-a;
                    a=c;
                    b=d;
                }
            }

            System.out.println(c==a && d==b ? numMoves : -1);
        }
    }
}