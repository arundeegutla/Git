import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;

public class prob2 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int[] cheese = {10, 9, 11, 10, 9, 9, 9, 9, 11, 10, 10, 9, 9, 9, 9, 10, 9, 11, 10, 11, 11, 11, 11, 10, 10, 9, 10, 10, 10, 10, 10, 11, 11, 10, 10, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 11, 11, 10, 10, 10, 10, 11, 11, 11, 11, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 12, 12, 12, 11, 11, 11, 12, 0};

        int cases = in.nextInt();
        while (cases-- > 0) {
            int num = in.nextInt();
            System.out.println(num +": " + cheese[num-1]);
        }

        // int[] arr = new int[100];
        // for (int i = 1; i < 100; i++) {

        //     int count = 0;
        //     int max = 0;
        //     HashMap<Integer, Integer> map = new HashMap<>();
        //     Queue<Integer> q = new ArrayDeque<>();

        //     map.put(i, 0);
        //     q.add(i);

        //     while (!q.isEmpty() && count < 99) {
        //         int num = q.poll();
        //         int travel = map.get(num);

        //         // System.out.println(num + " " + travel);
        //         int add = (num + 1) % 1000000000;
        //         int multiply = (num * 3) % 1000000000;
        //         int divide = (num/2) % 1000000000;

        //         if (!map.containsKey(add)) {      
        //             map.put(add, travel + 1);
        //             q.add(add);
        //             if (add <= 99) {
        //                 count++;
        //                 max = Math.max(max, travel + 1);
        //             }
        //         }

        //         if (!map.containsKey(multiply)) {      
        //             map.put(multiply, travel + 1);
        //             q.add(multiply);
        //             if (multiply <= 99) {
        //                 count++;
        //                 max = Math.max(max, travel + 1);
        //             }
        //         }

        //         if (!map.containsKey(divide)) {      
        //             map.put(divide, travel + 1);
        //             q.add(divide);
        //             if (divide <= 99) {
        //                 count++;
        //                 max = Math.max(max, travel + 1);
        //             }
        //         }


                
        //     }

        //     arr[i-1] = max;
        // }

        // System.out.println(Arrays.toString(arr));
        

    }
}
