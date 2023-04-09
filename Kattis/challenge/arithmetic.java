import java.util.Scanner;

public class arithmetic {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(Long.toString(Long.parseLong(in.nextLine(), 8), 16).toUpperCase());
    }
}
