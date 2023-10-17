import java.math.BigInteger;
import java.util.Scanner;

public class creditcard {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while (t-- > 0) {
            double rate = s.nextDouble(), bal = s.nextDouble(), pay = s.nextDouble();
            boolean pos = false;

            for (int i = 0; i <= 1200; i++) {
                bal += ((double) Math.round((bal * ((rate / 100) * 100))) / (double) 100);

                if (bal <= 0) {
                    System.out.println(i);
                    pos = true;
                    break;
                }

                bal -= pay;
            }

            if (!pos) System.out.println("impossible");

        }
    }
}
