import java.util.HashMap;
import java.util.Scanner;

public class immortalNew {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();


        for (int i = 0; i < numCases; i++) {
            in.nextInt();

            long n = in.nextLong();

            System.out.println(i+1 + " " + fb(n));
        }

        in.close();
    }

    private static int fb(long n) {

        double sqr5 = Math.sqrt(5);

        double greek1 = (1 + sqr5)/2;
        double greek2 = (1 - sqr5)/2;


        



        return (int) ((Math.pow(greek1, n)% 1000000000 - Math.pow(greek2, n)% 1000000000) / sqr5) ;
    }
}
