
import java.util.Scanner;

public class sequences {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int n = in.nextInt();

            int time = in.nextInt();

            int[] array = new int[n];

            for (int j = 0; j < n; j++) {
                array[j] = in.nextInt();
            }

            for (int j = 0; j < time; j++) {

                int x = 0;
                while (x+1 < n) {
                    array[x] = array[x] + array[x+1];
                    x++;
                }
                n--;
            }

            for (int j = 0; j < n; j++) {
                System.out.print(array[j] + (j == n-1 ? "" : " "));
            }

            System.out.println();
        }

        in.close();
    }
}
