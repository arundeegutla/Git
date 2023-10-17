import java.util.Scanner;

/**
 * babylonian
 */
public class babylonian {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        in.nextLine();
        while (numCases-->0) {
            String[] sep = (" " + in.nextLine()).replaceAll(",", ", ").split(",");
            long total = 0;
            loop:for (int i = 0; i < sep.length; i++) {
                int val = 0;
                try {
                    val = Integer.parseInt(sep[i].substring(1));
                } catch (Exception e) {
                    continue loop;
                }
                
                total += val * Math.pow(60, sep.length - i - 1);
            }
            System.out.println(total);
        }
    }
}