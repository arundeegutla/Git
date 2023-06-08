import java.util.Scanner;
/**
 * rectangle
 */
public class waffle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        double angle = ((in.nextInt()*180.0)/r) % 360;
        
        if (angle > 90 && angle < 270) {
            System.out.println("down");
        } else 
            System.out.println("up");

    }
}