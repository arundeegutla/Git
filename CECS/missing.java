import java.util.Scanner;

/**
 * missing
 */
public class missing {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        boolean[] check = new boolean[n];
        for (int i = 0; i < n - 1; i++) {
            check[in.nextInt() - 1] = true;
        }
        for (int i = 0; i < check.length; i++) {
            if (!check[i]) {
                System.out.println(i + 1);
                return;
            }
        }
    }
}