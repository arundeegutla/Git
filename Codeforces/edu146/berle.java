import java.util.Scanner;

/**
 * berle
 */
public class berle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            long n = in.nextLong();
            long k = in.nextLong();

            if (n%2 == 0 || k%2 != 0) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
            
        }
    }
}