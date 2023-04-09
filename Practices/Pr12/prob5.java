import java.util.Arrays;
import java.util.Scanner;

public class prob5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for (int p = 1; p <= cases; p++) {
            int numDice = in.nextInt();
            int multi = 1;
            int[] dice = new int[numDice];
            for (int i = 0; i < numDice; i++){
                dice[i] = in.nextInt();
                multi *= dice[i];
            }
            int sum = in.nextInt();
            int possibilities = getAll(dice, 0, sum);
            System.out.printf("%d: %.9f\n", p, (double)possibilities/multi);
        }
    }

    private static int getAll(int[] dice, int at, int sum) {
        if (at == dice.length && sum == 0)
            return 1;

        if (sum <= 0 || at == dice.length) 
            return 0;

        int count = 0;
        for (int i = 1; i <= dice[at]; i++)
            count += getAll(dice, at+1, sum - i);
        return count;
    }
}
