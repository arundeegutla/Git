import java.util.Arrays;
import java.util.Scanner;

public class pairs {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int len = in.nextInt();
            int operation = in.nextInt();
            in.nextLine();

            int[] smalls = new int[26];
            int[] bigs = new int[26];
            String line = in.nextLine();
            for (int i = 0; i < line.length(); i++) {
                if (Character.isUpperCase(line.charAt(i))) bigs[line.charAt(i) - 'A']++;
                else smalls[line.charAt(i) - 'a']++;
            }

            long count = 0;
            for (int i = 0; i < smalls.length; i++) {
                count += Math.min(bigs[i], smalls[i]);
                if (operation > 0 && smalls[i] < bigs[i]) {
                    bigs[i] -= smalls[i];
                    smalls[i] = 0;
                    int add = Math.min(operation, bigs[i]/2);
                    count += add;
                    operation-=add;
                } else if (operation > 0 && smalls[i] > bigs[i]) {
                    smalls[i] -= bigs[i];
                    bigs[i] = 0;
                    int add = Math.min(operation, smalls[i]/2);
                    count += add;
                    operation-=add;
                }
            }

            // System.out.println(Arrays.toString(smalls));
            // System.out.println(Arrays.toString(bigs));
            System.out.println(count);

        }
    }
}
