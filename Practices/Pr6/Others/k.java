import java.util.Scanner;

public class k {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int end = in.nextInt();
        in.nextLine();
        
        String numword = in.nextLine();
        
        int at = 1;

        for (int i = 0; at <= end; i++) {

            if (i >= numword.length()) {
                System.out.println(at);
                return;
            }

            if (i < 9 && numword.charAt(i)-'0' != (at)) {
                System.out.println(at);
                return;
            }

            if (i>=9 && (i+1 >= numword.length() || ( ((numword.charAt(i)-'0') * 10) + ((numword.charAt(i+1) - '0')) != (at) ))) {
                System.out.println(at);
                return;
            }

            if (i == 99 && i + 2 > numword.length()) {
                System.out.println(at);
                return;
            }

            if (i>=9) {
                i++;
            }

            at++;
        }

        in.close();
    }
}
