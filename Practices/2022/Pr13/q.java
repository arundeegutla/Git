import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;

public class q {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int a = in.nextInt();
        int b = in.nextInt();

        HashMap<Long, Integer> map = new HashMap<>();
        Queue<Long> q = new ArrayDeque<>();

        map.put((long)a, 0);
        q.add((long)a);

        while (true) {
            long num = q.poll();
            int travel = map.get(num);

            if (num % 2 == 0 && !map.containsKey(num/2)) {
                q.add(num/2);
                map.put(num/2, travel+1);
                if (num/2 == b) {
                    System.out.println(travel+1);
                    return;
                }
            }

            if (!map.containsKey(num+1)) {
                map.put(num+1, travel+1);
                q.add(num+1);
                if (num+1 == b) {
                    System.out.println(travel+1);
                    return;
                }
            }
        }

    }
}
