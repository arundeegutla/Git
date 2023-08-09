import java.util.Scanner;

public class f {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        in.nextLine();

        while (numCases-- > 0) {
            boolean[] used = new boolean[26];
            String sentece = in.nextLine().toLowerCase().replace(" ", "");

            for (char c : sentece.toCharArray())
                if (c - 'a' >= 0 && c - 'a' < 26)
                    used[c-'a'] = true;

            boolean isPanagram = true;

            StringBuilder missing = new StringBuilder("missing ");
            for (int i = 0; i < used.length; i++) {
                if (!used[i]) {
                    isPanagram = false;
                    missing.append((char)(i+'a'));
                }
            }

            if (isPanagram)
                System.out.println("pangram");
            else
                System.out.println(missing);
        }

        in.close();
    }
}