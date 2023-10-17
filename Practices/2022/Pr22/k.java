import java.util.Scanner;

/**
 * k
 */
public class k {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();
        int fhiphen = line.indexOf("-");
        if (fhiphen == -1) {
            System.out.println("NO");
            return;
        }

        if ((fhiphen > 1 && fhiphen <= 8) && (line.length() - (fhiphen + 1) >= 1 && line.length() - (fhiphen+1) <= 24)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}