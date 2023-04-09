import java.util.Scanner;

public class m {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();

        int[] arr = new int[b];
        int sum = 0;
        for (int i = 0; i < b; i++) {
            arr[i] = s.nextInt();
            sum += arr[i];
        }

        float min = (a - b) * -3;
        float max = (a - b) * 3;

        System.out.println((min + sum) / a + " " + (max + sum) / a);
    }
}
