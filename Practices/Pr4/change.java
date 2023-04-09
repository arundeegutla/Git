import java.time.Period;
import java.util.Scanner;

public class change {
   public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCents = in.nextInt();

        for (int i = 0; i < numCents; i++) {
            System.out.println(i+1 + " " + breakIt(in.nextInt()));
        }
   }

    private static String breakIt(int nextInt) {

        int quarters = 0, dimes = 0, nickel = 0;

        quarters = (int)nextInt/25;
        nextInt = nextInt - 25*quarters;

        dimes = nextInt/10;
        nextInt = nextInt - 10*dimes;

        nickel = nextInt/5;
        nextInt = nextInt - 5*nickel;

        return quarters + " QUARTER(S), " + dimes + " DIME(S), " + nickel + " NICKEL(S), " + nextInt + " PENNY(S)";
    } 
}
