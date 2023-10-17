import java.util.HashSet;
import java.util.Scanner;

public class d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        HashSet<String> set = new HashSet<>();
        String[] line = in.nextLine().split(" ");
        for (String word : line) {
            if (set.contains(word)) {
                System.out.println("no");
                return;
            }
            set.add(word);
        }

        System.out.println("yes");
    }
}
