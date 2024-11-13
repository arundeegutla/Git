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
            String[] val = in.nextLine().replaceAll(",", ", ").split(",");
            long num = 0;
            for (int i = 0; i < val.length; i++) {
                long thisNum = 0;
                try {
                    thisNum = Long.parseLong(val[i].substring(i==0 ? 0 : 1));
                } catch (Exception e) {
                    thisNum = 0;
                }
                num += thisNum * Math.pow(60, val.length - i - 1);
            }

            System.out.println(num);

        }

    }
}