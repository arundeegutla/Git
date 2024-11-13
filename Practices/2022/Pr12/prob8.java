import java.util.Scanner;

public class prob8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num;
        while ((num = in.nextInt()) != 0) {
            boolean polite = false;
            for (int i = 1; i <= num/2; i++) {
                int count = i;
                for (int j = i+1; j <= (num+1)/2; j++) {
                    count += j;
                    if (count == num) {
                        polite = true;
                        System.out.println(num + " = " + i + " to " + j);
                        break;
                    } else if (count > num)
                        break;
                }
            }
            if (!polite)
                System.out.println(num + " is not polite");
        }
    }
}
