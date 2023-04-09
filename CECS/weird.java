import java.util.Scanner;
/**
 * weird
 */
public class weird {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextInt();
        StringBuilder str = new StringBuilder(n + " ");
        while (n != 1) {
            if((n&1)==1)
                n = (n*3) + 1;
            else
                n /= 2;
            str.append(n + " ");
        }
        System.out.println(str.replace(str.length()-1, str.length(), ""));
    }
    
}