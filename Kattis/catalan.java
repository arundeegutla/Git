import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by martinpettersson on 29/12/14.
 */
public class catalan {
    Scanner io = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    final static BigInteger ONE = BigInteger.ONE;

    public static void main(String[] args) {
        new catalan();
    }

    public catalan() {
        int q = io.nextInt();
       // generateTestData();
        for (int number = 0; number < q; number++) {
            int x = handleInput();
            out.println(catalanNumber(x));
        }
        io.close();
        out.flush();
    }

    BigInteger catalanNumber(int x) {
        BigInteger cx = bigFactorial(2 * x).divide(bigFactorial(x + 1).multiply(bigFactorial(x)));
        return cx;
    }

    BigInteger bigFactorial(int n) {
        BigInteger inc = ONE; BigInteger fact = ONE;
        for (int c = 1; c <= n; c++) {
            fact = fact.multiply(inc);
            inc = inc.add(ONE);
        }
        return fact;
    }

    // delete me!
    void generateTestData() {
        Random r =  new Random();
        for (int i = 0; i < 1000; i++) {
            System.err.println(r.nextInt(4999));
        }
    }

    int handleInput() {
        int inputNumber = io.nextInt();
        return inputNumber;
    }
}