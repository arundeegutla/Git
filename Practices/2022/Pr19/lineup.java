import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class lineup {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numNames = in.nextInt();
        String[] names = new String[numNames];
        String[] increasing = new String[numNames];
        String[] decreasing = new String[numNames];

        for (int i = 0; i < numNames; i++) {
            String name = in.next();
            names[i] = name;
            increasing[i] = name;
            decreasing[i] = name;
        }

        Arrays.sort(increasing);
        Arrays.sort(decreasing, Comparator.reverseOrder());
        
        if (Arrays.equals(names, increasing))
            System.out.println("INCREASING");
        else if (Arrays.equals(names, decreasing))
            System.out.println("DECREASING");
        else
            System.out.println("NEITHER");
    }
}
