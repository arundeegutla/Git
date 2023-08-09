import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String table = in.next();

        for (int i = 0; i < 5; i++) {
            String car = in.next();
            if(car.charAt(0) == table.charAt(0)){
                System.out.println("YES");
                return;
            }
            if(car.charAt(1) == table.charAt(1)){
                System.out.println("YES");
                return;
            }

        }

        System.out.println("NO");
    }
}