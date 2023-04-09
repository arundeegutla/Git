import java.util.HashSet;
import java.util.Scanner;

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int start = in.nextInt();
        int end = in.nextInt();

        int count = 0;

        for (int i = start; i <= end; i++) {
            if(isPossible(i)) count++;
        }
        System.out.println(count);

        in.close();
    }



    private static boolean isPossible(int key) {

        String keyAsString = String.valueOf(key);

        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < keyAsString.length(); i++) {

            double check = key / (double)(keyAsString.charAt(i) - '0');
            if (check != (int)check || set.contains(keyAsString.charAt(i) - '0')) {
                return false;
            }

            set.add(keyAsString.charAt(i) - '0');
        }

        return true;
    }
}
