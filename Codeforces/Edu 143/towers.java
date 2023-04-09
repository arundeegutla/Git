import java.util.Scanner;
/**
 * towers
 */
public class towers {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCase = in.nextInt();
        loop : while (numCase-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();
            in.nextLine();
            String first = in.nextLine();
            String second = in.nextLine();
            boolean f = check(first);
            boolean s = check(second);
            
            if (!f && !s) {
                System.out.println("no");
                continue loop;
            }

            if (f && s) {
                System.out.println("Yes");
                continue loop;
            }

            if (second.length() > 1) {
                StringBuilder fs = new StringBuilder(first);
                StringBuilder ss = new StringBuilder(second);

                for (int i = second.length() - 1; i > 0 && (!check(fs) || !check(ss)); i--) {
                    ss.deleteCharAt(ss.length() - 1);
                    fs.append(second.charAt(i) + "");
                }

                if (check(fs) && check(ss)) {
                    System.out.println("yes");
                    continue loop;
                }
            }

            if (first.length() > 1) {
                StringBuilder fs = new StringBuilder(first);
                StringBuilder ss = new StringBuilder(second);

                for (int i = first.length() - 1; i > 0 && (!check(fs) || !check(ss)); i--) {
                    fs.deleteCharAt(fs.length() - 1);
                    ss.append(first.charAt(i) + "");
                }

                if (check(fs) && check(ss)) {
                    System.out.println("yes");
                    continue loop;
                }
            }

            System.out.println("no");

            
        }
    }

    private static boolean check(String s) {
        for (int i = 0; i+1 < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                return false;
            }
        }
        return true;
    }

    private static boolean check(StringBuilder s) {
        for (int i = 0; i+1 < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i+1)) {
                return false;
            }
        }
        return true;
    }
}