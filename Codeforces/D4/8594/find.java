import java.util.HashMap;
import java.util.Scanner;

public class find {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        loop:while(numCases-->0) {
            int size = in.nextInt();
            in.nextLine();
            String line = in.nextLine();
            HashMap<Character, Boolean> map = new HashMap<>();
            boolean prev = false;

            for (int i = 0; i < line.length(); i++) {
                if (map.containsKey(line.charAt(i)) && (map.get(line.charAt(i)) != !prev)) {
                    System.out.println("no");
                    continue loop;
                }
                if (!map.containsKey(line.charAt(i)))
                    map.put(line.charAt(i), !prev);
                prev = !prev;
            }

            System.out.println("yes");
        }
    }
}
