import java.util.Scanner;

/**
 * i
 */
public class i {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int count = 0;
        int[][] numbers = new int[2][2];
        for (int i = 0; i < 10; i++) {
            int test = in.nextInt();
            if (test != 0) {
                numbers[count][0] = test;
                numbers[count][1] = i;
                count++;
            }
        }

        double constant = (double)(numbers[1][0] - numbers[0][0])/(numbers[1][1] - numbers[0][1]);

        if ((constant % 1) == 0) {

            for (int i = 0; i < 10; i++) {
                System.out.print(numbers[0][0] - (int)constant * (numbers[0][1] - i) + (i == 9 ? "\n" : " "));
            }
            
        } else System.out.println(-1);

    }
}