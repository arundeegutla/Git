import java.math.BigInteger;
import java.util.Scanner;

public class k {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder line = new StringBuilder(in.nextLine());

        if (!(new BigInteger(line.toString()).isProbablePrime(15))) {
            System.out.println("no");
            return;
        }

        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) == '3' || line.charAt(i) == '4' || line.charAt(i) == '7') {
                System.out.println("no");
                return;
            }
            if (line.charAt(i) == '6') {
                line.setCharAt(i, '9');
            } else if (line.charAt(i) == '9') {
                line.setCharAt(i, '6');
            }

        }
        line = line.reverse();

        if (!(new BigInteger(line.toString()).isProbablePrime(15))) {
            System.out.println("no");
            return;
        }

        System.out.println("yes");

    }
}
