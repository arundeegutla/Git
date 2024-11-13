import java.util.ArrayList;
import java.util.Scanner;

public class i {
    public static void main(String[] args) {

        ArrayList<Character> index = new ArrayList<>();
        for (int i = 0; i <= 9; i++) index.add((char)(i+'0'));
        for (char i = 'A'; i <= 'Z'; i++) index.add(i);
        for (char i = 'a'; i <= 'z'; i++) index.add(i);

        Scanner in = new Scanner(System.in);

        double p = in.nextInt();
        double q = in.nextInt();
        double n = in.nextDouble();
        if (n == 0) {
            System.out.println(0);
            return;
        }

        StringBuilder str = new StringBuilder();

        while (n > 0) {
            int ind = (int)(n%p);
            str.insert(0, index.get(ind));
            n -= ind;
            n = (q*n/p);
            
        }

        System.out.println(str);
    }
}
