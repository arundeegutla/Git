import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n;

        while ((n=in.nextInt()) != 0) {
            in.nextLine();

            Queue<String> top = new ArrayDeque<>();
            Queue<String> bottom = new ArrayDeque<>();

            int i;
            for (i = 0; i < ((n/2) + (n%2 == 0 ? 0 : 1)); i++)
                top.add(in.nextLine());

            for (; i < n; i++)
                bottom.add(in.nextLine());

            for (int j = 0; j < n; j++) {
                
                if (j%2 == 0 || bottom.isEmpty())
                    System.out.println(top.poll());
                else 
                    System.out.println(bottom.poll());

            }

        }
    }
}
