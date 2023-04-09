import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        while (numCases-- > 0) {
            int n = in.nextInt();
            if (n%2 == 0) {
                System.out.println(1 + " " + (n/2));
            } else
                System.out.println(-1);
        }
        

    }

}