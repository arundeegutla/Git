import java.util.Scanner;

public class lexi {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int len = in.nextInt();
            char[] str = in.next().toCharArray();

            int index = -1;
            char val = '{';

            for (int i = 0; i < str.length; i++) {
                if (str[i] <= val) {
                    val = str[i];
                    index = i;
                }
            }

            StringBuilder s = new StringBuilder();
            for (int i = 0; i < str.length; i++) {
                if (i == index) {
                    s.insert(0, str[i]);
                } else {
                    s.append(str[i]);
                }
            }
            System.out.println(s);
        }
    }
}
