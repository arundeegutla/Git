import java.util.Scanner;
public class j {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        in.nextLine();
        while (num-- > 0) {
            String str = in.nextLine();
            System.out.println(str.length());
        }
        
    }
}