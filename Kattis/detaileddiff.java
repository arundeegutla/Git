import java.util.Scanner;

/**
 * detaileddiff
 */
public class detaileddiff {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            String a = in.next();
            String b = in.next();
            System.out.println(a);
            System.out.println(b);
            for (int i = 0; i < a.length(); i++) {
                if(a.charAt(i)!=b.charAt(i)) System.out.print('*');
                else System.out.print('.');
            }
            System.out.println("\n");
        }
    }
}