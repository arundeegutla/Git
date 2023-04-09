import java.util.Scanner;

public class five {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numTiks = in.nextInt();
        for (int i = 0; i < numTiks; i++) {
            System.out.println(5 * in.nextInt());
        }
    }
}
