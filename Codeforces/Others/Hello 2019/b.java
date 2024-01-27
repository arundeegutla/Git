import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numTurns = in.nextInt(); 

        int[] turns = new int[numTurns];

        for (int i = 0; i < turns.length; i++) {
            turns[i] = in.nextInt();
        }


        System.out.println((isPos(turns, 0, 0) ? "YES" : "NO"));
    }

    private static boolean isPos(int[] turns, int at, int index) {

        if (index == turns.length && at == 0) {
            return true;
        }

        if (index == turns.length) {
            return false;
        }

        return isPos(turns, (at - turns[index]) % 360, index + 1) || isPos(turns, (at + turns[index]) % 360, index + 1);
    }


}
