import java.math.BigDecimal;
import java.math.MathContext;
import java.util.Scanner;

public class points {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0)
            System.out.println(new BigDecimal(in.nextLong()-1).sqrt(new MathContext(50)).longValue());
    }
}
