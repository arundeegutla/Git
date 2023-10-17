import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class magicalcows {
    public static long[] cows = new long[1001];
    public static int capacity;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        capacity = in.nextInt();
        int numFarms = in.nextInt();
        int numVisits = in.nextInt();

        boolean[] visits = new boolean[51];
        long[] ans = new long[51];

        while (numFarms-->0)
            cows[in.nextInt()]++;

        ArrayList<Integer> days = new ArrayList<>();
        while (numVisits-->0)
        {
            days.add(in.nextInt());
            visits[days.get(days.size() - 1)] = true;
        }


        for (int i = 0; i <= 50; i++) 
        {
            if (visits[i])  
                ans[i] = getCount();
            update();
        }

        for (int day : days)
            System.out.println(ans[day]);
    }

    private static void update() {

        long[] copy = Arrays.copyOf(cows, cows.length);
        for (int i = 0; i <= capacity; i++) {
            if (i*2 > capacity)
                copy[i] += cows[i];
            else 
            {
                copy[i*2] += cows[i];
                copy[i] -= cows[i]; 
            }
        }
        cows = copy;

    }

    private static long getCount() {
        long numFarms = 0;
        for (int i = 0; i <= capacity; i++)
            numFarms += cows[i];
        return numFarms;
    }
}
