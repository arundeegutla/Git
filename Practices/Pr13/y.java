import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;


public class y {
    public static void main(String[] args) {
        // System.out.println(Long.MAX_VALUE);

        Scanner in = new Scanner(System.in);
        int[] lengths = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
        int[] firstNumber = {0, 1, 4, 9, 6, 5};


        String ans = in.nextLine();

        int index = Arrays.binarySearch(lengths, ans.length());
        int start2 = -1;

        for (int i = 0; i < firstNumber.length; i++) {
            if (ans.charAt(0)-'0' == firstNumber[i]) {
                start2 = i;
                break;
            }
        }

        if (index < 0 || start2 < 0) {
            System.out.println("-1");
            return;
        }

        HashSet<String> set = new HashSet<>();
        long num = (long)Math.pow(10, index) * start2;
        String thisAns = "";


        while (!thisAns.equals(ans)) {
            thisAns = multiply(num);
            if (set.contains(thisAns))
                break;

            System.out.println("(" + num + ", " + thisAns + ")");
            num++;
            set.add(thisAns);
        }
        if (thisAns.equals(ans)) {
            System.out.println(num-1);
        } else {
            System.out.println(-1);
        }



        // ArrayList<String> list = new ArrayList<>();
        // HashSet<String> set = new HashSet<>();
        // for (int i = 0; String.valueOf(i).length() <= 4; i++) {
        //     String ans = multiply(i);


        //     if (ans.length() > 25) {
        //         break;
        //     }

        //     if (!set.contains(ans)) {
        //         set.add(ans);
        //         list.add(ans);
        //         System.out.println("(" + i + ", " + ans + ")");
        //     } else {
        //         System.out.println(i + ", " + ans);
        //         // i += i-3;
        //     }
        // }


        // System.out.println(list.size());
    }

    public static String multiply(long x) {
        char[] c = String.valueOf(x).toCharArray();

        Queue<String> adds = new ArrayDeque<>();

        long times = 1;
        for (int i = c.length - 1; i >= 0; i--) {

            StringBuilder tot = new StringBuilder();

            for (int j = c.length - 1; j >= 0; j--) {
                int num = ((c[i]-'0') * (c[j]-'0')) % 10;
                tot.insert(0, num);
            }

            BigInteger num = new BigInteger(tot.toString()).multiply(new BigInteger(String.valueOf(times)));
            adds.add(num.toString());
            times *= 10;
        }


        while (adds.size() >= 2) {
            String one = adds.poll();
            String two = adds.poll();
            adds.add(addition(new StringBuilder(one), new StringBuilder(two)));
        }

        return adds.poll();
    }

    static String addition(StringBuilder x, StringBuilder y) {

        if (x.length() < y.length()) {
            StringBuilder temp = new StringBuilder(x);
            x = y;
            y = temp;
        }

        char[] x_array = x.toString().toCharArray();
        char[] y_array = y.toString().toCharArray();

        StringBuilder str = new StringBuilder();

        int y_at = y_array.length - 1;
        for (int i = x_array.length - 1; i >= 0 ; i--) {
            if (y_at >= 0) {
                str.insert(0, (x_array[i]-'0' + y_array[y_at]-'0') % 10);
                y_at--;
            } else {
                str.insert(0, (x_array[i]-'0') % 10);
            }
        }


        return str.toString();
    }
}
