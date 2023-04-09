import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += in.nextInt();
        System.out.println(sum*5);
    }
}
