import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int sum = 0;
        int count = 0;
        for (int i = 0; i < num; i++) {
            int at = in.nextInt();
            if (at >= 0) {
                count++;
                sum += at;
            }
        }
        System.out.println((double)sum/count);
    }
}
