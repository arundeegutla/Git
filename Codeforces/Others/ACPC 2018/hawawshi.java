import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * hawawshi
 */
public class hawawshi {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("hawawshi.in"));

        int numCases = in.nextInt();
        StringBuilder str = new StringBuilder();

        while (numCases-- > 0) {

            int n = in.nextInt();
            int x = in.nextInt();
            int A = in.nextInt();
            int B = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            int p = in.nextInt();

            int bottom = (B-A+1);
            int count = 0;

            for (int i = A; i <= B; i++)
                if (generateSequence(a, b, p, i, x, n))
                    count++;

            int gcd = gcd(count, bottom);

            str.append(String.format("%d/%d\n", count/gcd, bottom/gcd));
        }

        System.out.println(str.toString());
    }

    private static boolean generateSequence(int a, int b, int p, int i, int x, int n) {

        int rn = i;

        for (int j = 0; j < n; j++) {
            if (rn == x)
                return true;
            rn = (a*rn + b) % p;
        }
        
        return false;
    }

    public static int gcd(int a, int b)
    {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp%b;
        }
        return a;
    }
}