import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String in = s.nextLine();
        System.out.println(in.substring(0, 3).equals("555") ? "YES" : "NO");
    }
}
