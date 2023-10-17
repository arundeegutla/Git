import java.util.Arrays;
import java.util.Scanner;

public class n {

    static long res;
    static int[] combo;
    static boolean[] incombo;
    static int[] arr;

    static int total;
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        res = 0;
        total = 0;

        combo = new int[n];
        incombo = new boolean[n];

        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = s.nextInt();

        if (n < 3) {
            System.out.println(0);
            return;
        }

        combo(0, 0, 3, n);

        System.out.println("TOTAL: " + total);
        System.out.println(res);
    }

    static void combo(int amtincombo, int index, int size, int n) {
        if (amtincombo == size) {
            int[] op = new int[3];
            
            int s = 0;
            for (int i = 0; i < n; i++) {
                if (incombo[i]) {
                    op[s] = arr[i];
                    s++;
                }
            }
            
            total++;
            Arrays.sort(op);
            if (op[0] + op[1] > op[2]) res++;
        } else if (index < n) {
            incombo[index] = true;
            combo[amtincombo] = arr[index];
            combo(amtincombo + 1, index + 1, size, n);
            incombo[index] = false;
            combo(amtincombo, index + 1, size, n);
        }
    }
}
