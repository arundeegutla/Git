import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class prob1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int num = 1;
        while (true) {
            int n = s.nextInt(), people = s.nextInt();
            s.nextLine();

            if (n == 0) break;

            String[] hydrantPeople = new String[n];
            Arrays.fill(hydrantPeople, "");
            boolean[] hydrants = new boolean[n];

            ArrayList<String> notFound = new ArrayList<String>();

            for (int i = 0; i < people; i++) {
                String[] in = s.nextLine().split(" ");
                String name = in[0];

                boolean found = false;
                for (int j = 1; j < in.length; j++) {
                    if (in[j].equals("")) continue;

                    if (!hydrants[Integer.parseInt(in[j]) - 1]) {
                        hydrants[Integer.parseInt(in[j]) - 1] = true;
                        hydrantPeople[Integer.parseInt(in[j]) - 1] = name;
                        found = true;
                        break;
                    }
                }

                if (!found) notFound.add(name);
            }

            System.out.println("Set " + num);
            for (int i = 1; i <= n; i++) {
                System.out.println(i + ": " + hydrantPeople[i - 1]);
            }

            if (notFound.size() != 0) {
                System.out.println("Unable to adopt");
                for (String str : notFound) System.out.println(str);
            }

            System.out.println();
            num++;
        }
    }
}
