import java.util.Scanner;

public class ladder {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double h = in.nextInt();
        double angle = in.nextDouble();
        System.out.println((int)Math.ceil(h/Math.sin(Math.toRadians(angle))));
    }
}
