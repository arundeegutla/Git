import java.util.Scanner;

/**
 * simon
 */
public class simon {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numLines = in.nextInt();
        in.nextLine();
        while (numLines-->0) {
            String line = in.nextLine();
            if (line.indexOf("Simon says") == 0) {
                System.out.println(line.replaceAll("Simon says", ""));
            }
        }
    }
}