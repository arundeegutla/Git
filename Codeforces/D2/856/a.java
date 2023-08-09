import java.util.ArrayList;
import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        loop : while (numCases-->0) {
            int len = in.nextInt();
            ArrayList<String> fixes = new ArrayList<>();

            for (int i = 0; i < (2*len - 2); i++)
                fixes.add(in.next());

            for (int i = 0; i < fixes.size(); i++) {
                StringBuilder str = new StringBuilder(fixes.get(i)).reverse();
                boolean found = false;
                for (int j = 0; j < fixes.size(); j++) {
                    if(i==j)continue;
                    if (fixes.get(j).equals(str.toString())) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    System.out.println("no");
                    continue loop;
                }
            }

            System.out.println("yes");

        }
    }
}