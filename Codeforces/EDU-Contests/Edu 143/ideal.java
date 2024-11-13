import java.util.Scanner;

public class ideal {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        loop : while (numCases-- > 0) {
            int numEdges = in.nextInt();
            int point = in.nextInt();
            boolean startF = false;
            boolean endF = false;
            while (numEdges-- > 0) {
                int start = in.nextInt();
                int end = in.nextInt();
                if (start == point)
                    startF = true;
                if (end == point)
                    endF = true;
            }
            if (startF && endF) {
                System.out.println("Yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
