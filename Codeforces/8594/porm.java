import java.util.Scanner;

/**
 * porm
 */
public class porm {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            if (a+b==c) {
                System.out.println("+");
            } else {
                System.out.println("-");
            }
        }
    }
}