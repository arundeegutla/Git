import java.util.Scanner;

public class letters {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int len = in.nextInt();
            in.nextLine();
            String line = in.nextLine();
            String prev = "";

            int count = 0;
            for (int i = 0; i+1 < line.length(); i++) {
                if (prev == "" || !check(prev, line.charAt(i) + "" + line.charAt(i+1))) {
                    count++;
                    prev = line.charAt(i) + "" + line.charAt(i+1);
                }
            }
            System.out.println(count);
        }
    }

    private static boolean check(String prev, String string) {
        return string.equals(prev) || new StringBuilder(prev).reverse().toString().equals(string);
    }
}
