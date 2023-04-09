import java.util.*;

public class g
{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = in.nextInt();
        }

        int curX = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                curX = a[j] - a[i];
                if (curX < 0)
                {
                    System.out.println("no");
                    System.exit(0);
                }
            }
        }

        System.out.println("yes");
    }
}