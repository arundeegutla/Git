import java.math.BigInteger;
import java.util.Scanner;

public class prob7 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while (s.hasNextLine()) {

            String start = s.next();
            BigInteger startBig = new BigInteger(start);

            int reps = s.nextInt();

            int found = -1;
            for (int i = 0; i <= reps; i++) {
                if (checkPalin(startBig)){
                    found = i;
                    break;
                }
                startBig = startBig.add(getReverse(startBig));
            }
            
            System.out.println(start + ": " + (found == -1 ? ("no palindrome found in " + reps + " repetitions") : startBig.toString() + " (" + found + " repetitions)"));
        }
    }

    static BigInteger getReverse(BigInteger curr) {
        StringBuilder rev = new StringBuilder(curr.toString()).reverse();
        return new BigInteger(rev.toString());
    }

    static boolean checkPalin(BigInteger curr) {
        StringBuilder rev = new StringBuilder(curr.toString()).reverse();
        StringBuilder comp = new StringBuilder(curr.toString());
        return rev.toString().equals(comp.toString());
    }
}
