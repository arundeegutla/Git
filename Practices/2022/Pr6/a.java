import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class a {

    static HashMap<Character, Integer> mappedvals;
    static char[] in;
    static char[] op = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    static boolean[] inperm;
    static char[] perm;
    static int min;
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        in = s.nextLine().toCharArray();

        inperm = new boolean[9];
        perm = new char[9];

        min = Integer.MAX_VALUE;
        perm(8, 0);
        System.out.println(min);
    }

    static void perm(int n, int index) {
        if (index == n) {
            int sum = 0;
            mappedvals = new HashMap<Character, Integer>();
            for (int i = 0; i < 9; i++)
                mappedvals.put(perm[i], i);
            
            int indexat = perm[0];
            for (int i = 0; i < n; i++) {
                
            }

            min = Math.min(sum, min);
        } else {
            for (int i = 0; i < n; i++) {
                inperm[i] = true;
                perm[index] = op[i];
                perm(n, index + 1);
                inperm[i] = false;
            }
        }
    }
}
