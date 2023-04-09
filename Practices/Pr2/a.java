import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int p1 = in.nextInt();
        int q1 = in.nextInt();
        int p2 = in.nextInt();
        int q2 = in.nextInt();

        int ps = p1 * p2;
        int qs = q1 * q2;

        double area = ((double)ps/qs) / 2;

        if (area == (int)area) {
            
            System.out.println(1);
            
        } else System.out.println(0);

        in.close();

    }
}
