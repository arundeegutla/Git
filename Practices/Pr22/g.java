import java.util.Scanner;

public class g {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long n = s.nextLong(), steps = 0;
        while (n != 1) {
            if (n % 2 == 0) n /= 2;
            else n++;
            steps++;
        }
        System.out.println(steps);
    }
}
