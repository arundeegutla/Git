import java.util.Scanner;

public class luhn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        in.nextLine();

        for (int i = 0; i < numCases; i++) {
            String n = in.nextLine();

            if (getLuhnsNumber(n) % 10 == 0)
                System.out.println("PASS");
            else 
                System.out.println("FAIL");

        }

        in.close();
    }

    private static long getLuhnsNumber(String n) {
        long total = 0;

        for (int i = 0; i < n.length(); i++) {



            if (i % 2 == 0) {
                total += n.charAt(n.length() - i - 1) - '0';
            } else {

                int multi = (n.charAt(n.length() - i - 1) - '0') * 2;

                if (multi > 9) {
                    
                    multi = (multi%10) + (multi/10);

                }

                total += multi;
            }
        }

        return total;
    }

}
