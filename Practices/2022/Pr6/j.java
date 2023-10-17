import java.util.HashSet;
import java.util.Scanner;

public class j {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String word = in.nextLine();

        HashSet<String> set = new HashSet<>();
        int i = 0;

        for (i = 0; i < word.length(); i++) {
            if (set.contains(word.charAt(i) + "")) {
                System.out.println(0);
                return;
            } else {
                set.add(word.charAt(i) + "");
            }
        }

        
        System.out.println(1);
        in.close();
    }
}
