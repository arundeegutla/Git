import java.util.Scanner;
public class fahrenheit {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] nums = in.nextLine().split("/");
        long Fnumerator = Integer.parseInt(nums[0]);
        long Fdenominator = Integer.parseInt(nums[1]);

        long thisGcd = gcd(Fnumerator, Fdenominator);
        Fnumerator /= thisGcd;
        Fdenominator /= thisGcd;

        Fnumerator -= (Fdenominator * 32);
        Fnumerator *= 5;
        Fdenominator *= 9;

        long gcd = gcd(Fnumerator, Fdenominator);

        Fnumerator /= gcd;
        Fdenominator /= gcd;

        if (Fnumerator < 0 && Fdenominator < 0) {
            Fnumerator = -Fnumerator;
            Fdenominator = -Fdenominator;
        } else if (Fdenominator < 0) {
            Fnumerator = -Fnumerator;
            Fdenominator = -Fdenominator;
        }


        System.out.println((Fnumerator) + "/" + (Fdenominator));
    }

    public static long gcd(long a, long b)
    {
        while (b != 0) {
            long temp = a;
            a = b;
            b = temp%b;
        }
        return a;
    }

}

// c = (x/y) 5
//     ~~~~~~~
//        9