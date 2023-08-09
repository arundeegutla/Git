import java.util.HashSet;
import java.util.Scanner;

public class d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numWords = in.nextInt();
        int totalQuestions = in.nextInt() - 1;
        in.nextLine();

        int count = 0;
        loop : for (int i = 0; i < numWords; i++) {
            char[] line = in.nextLine().toCharArray();
            HashSet<Character> set = new HashSet<>();
            for (char c : line) {
                if (set.contains(c) || (int)(c - 'A') > totalQuestions)
                    continue loop;
                set.add(c);
            }
            count++;
        }
        System.out.println(count);
    }
}
