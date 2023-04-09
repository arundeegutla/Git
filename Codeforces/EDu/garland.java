import java.util.HashMap;
import java.util.Scanner;

/**
 * garland
 */
public class garland {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        in.nextLine();
        while (numCases-->0) {
            HashMap<Character, Integer> set = new HashMap<>();

            char[] bulbs = in.nextLine().toCharArray();
            int maxSame = 0;
            for (int i = 0; i < bulbs.length; i++) {
                if (!set.containsKey(bulbs[i]))
                    set.put(bulbs[i], 0);
                set.put(bulbs[i], set.get(bulbs[i]) + 1);
                maxSame = Math.max(maxSame, set.get(bulbs[i]));
            }

            if (maxSame == 1 || maxSame == 2) {
                System.out.println(4);
            } else if (maxSame == 3) {
                System.out.println(6);
            } else {
                System.out.println(-1);
            }
        }
    }
}