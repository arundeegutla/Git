import java.util.Scanner;

public class b_new {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        while (numCases-->0) {
            int numDice = in.nextInt();
            int total = in.nextInt();
            int r = in.nextInt();

            int divid = (r/(numDice-1));
            System.out.print(total-r + " ");
            for (int i = 0; i < numDice-2; i++) {
                r -= divid;
                System.out.print(divid + " ");
            }
            System.out.println(r);
        }
        
    }

}
