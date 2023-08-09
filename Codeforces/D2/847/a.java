import java.math.BigDecimal;
import java.util.Scanner;

/**
 * a
 */
public class a {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        String pi = "314159265358979323846264338327";

        int numCases = in.nextInt();
        in.nextLine();
        while (numCases-- > 0) {
            String line = in.nextLine();
            int count = 0;
            for (int i = 0; i < line.length(); i++) {
                if (pi.charAt(i) != line.charAt(i))
                    break;
                count++;
            }
            System.out.println(count);
        }


    }
}